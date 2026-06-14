#include<stdio.h>
#include<stdlib.h>
#include<SDL3/SDL.h>
#include<SDL3/SDL_stdinc.h>
#include<time.h>
#include<SDL3/SDL_surface.h>
#include"stacklist2.h"
#include<string.h>
typedef struct imageViewer{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    int width;
    int height;
    SDL_Event event;
    int run;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8* new_r;
    Uint8* new_g;
    Uint8* new_b;
    Uint8* new_a;
    struct stack* new_stack;
    SDL_Surface* wSurface;
    int isDropped;

} imgView;//deals with most of the variables needed in this programme
SDL_FRect* newRect;


imgView* imageV_init(int height,int width);
 char *new_str(const char *data);
int blitPicture(imgView* img);
void gameLoop(imgView* img);//main loop for the app
int input_section(imgView* img);//takes all the input related stuff
int render(imgView* img);//renders whatever needs to be rendered
SDL_FRect* makeRect(imgView* img,int x, int y);//Makes rectangles draw on the renderer given x and y position
int Garbage_collector(imgView* img);// free all the memory assigned for SDL_FRect type of pointers


int main(){//entry point
    SDL_Init(SDL_INIT_VIDEO);
    imgView* img=imageV_init(500,500);
    img->new_stack=stack_init();
    img->window=SDL_CreateWindow("ImageViewer",img->width,img->height,0);
    img->renderer=SDL_CreateRenderer(img->window,NULL);
    // img->surface=SDL_CreateSurface(img->width,img->height,SDL_PIXELFORMAT_UNKNOWN);
    // img->wSurface=SDL_GetWindowSurface(img->window);
    img->surface=SDL_LoadPNG("./One.png");
    img->surface=SDL_ScaleSurface(img->surface,img->width,img->height,SDL_SCALEMODE_LINEAR);
     img->wSurface=SDL_GetWindowSurface(img->window);
    if(img->surface==NULL){
        printf("Unable to load image");
        return 0;
     }
    //  blitPicture(img);
    // render(img);//rendering the window and drawing things
    gameLoop(img);
    // Garbage_collector(img);//freeing the alocated memory for the sdl_Frect* type 
stack_destroy(img->new_stack);
SDL_DestroyRenderer(img->renderer);
SDL_DestroySurface(img->surface);
SDL_DestroySurface(img->wSurface);
SDL_Quit();
    free(img);//freeing the space in heap aloocated for img 
    

    return 0;
}


imgView* imageV_init(int height,int width){
    imgView* view=(imgView*)malloc(sizeof(imgView));
    view->width=width;
    view->height=height;
    view->window=NULL;
    view->renderer=NULL;
    view->run=1;
    view->r=250;
    view->g=234;
    view->b=145;
    view->wSurface=SDL_GetWindowSurface(view->window);
    view->isDropped=0;//Not dropped yet or false
    
    // view->new_stack->listhead=NULL;
    // view->event=(SDL_Event*)malloc(sizeof(SDL_Event));
    return view;

}
void gameLoop(imgView* img){
    while(img->run){
        input_section(img);
        render(img);

        Garbage_collector(img);
   
}
}
int render(imgView* img){
    SDL_RenderClear(img->renderer);
    SDL_SetRenderDrawColor(img->renderer,img->r,img->g,img->b,1);
    SDL_RenderClear(img->renderer);
    // newRect=makeRect(img,500-20,25);
    
    //  img->wSurface=SDL_GetWindowSurface(img->window);
    SDL_FRect* newRect2=makeRect(img,0,500-100);
    // if(img->event.type==SDL_EVENT_DROP_FILE){
    //     // const char *file=new_str(img->event.drop.data);
    //     printf("%s",img->event.drop.data);
    //     img->surface=SDL_LoadSurface(new_str(img->event.drop.data));
    //     // img->surface=SDL_LoadPNG(img->event.drop.data);
    // }
    if(img->isDropped){
    img->surface=SDL_ScaleSurface(img->surface,img->width,img->height,SDL_SCALEMODE_NEAREST);
    if(img->surface==NULL){
        // printf("Could not scale surface");
        // printf("%s",SDL_GetError());
        // // SDL_Quit();
    }
    img->isDropped=0;
}
SDL_BlitSurface(img->surface,NULL,img->wSurface,NULL);//For blitting the surface 
    // blitPicture(img);
    // for(int i=0;i<img->width;i++){
    //     for(int j=0;j<img->height;j++){
    //         if(!SDL_ReadSurfacePixel(img->surface,i,j,img->new_r,img->new_g,img->new_b,img->new_a)){
    //             printf("couldn't read pixel!!");
    //         }
    //         if(!SDL_WriteSurfacePixel(img->wSurface,i,j,*(img->new_r),*(img->new_g),*(img->new_b),*(img->new_a))){
    //             printf("could not write the pixel ");
    //         };

    //     }
    // }
    //  FILE* file=fopen("One.png.png","r");
    //  img->surface=SDL_LoadPNG("./One.png");
    //  if(img->surface==NULL){
    //     printf("Unable to load image");
    //     return 0;
    //  }
    // if(!SDL_UpdateWindowSurface(img->window)){
    //     printf("Unable to update the window surface !");
    // }
    // SDL_SetRenderDrawColor(img->renderer,0,0,255,1);
    // SDL_RenderRect(img->renderer,newRect);
    // SDL_RenderFillRect(img->renderer,newRect);
    // SDL_RenderClear(img->renderer);
    // if(!SDL_RenderPresent(img->renderer)){
    //     SDL_Log("Failed to render!!");
    //     return 0;
    // }
    if(!SDL_UpdateWindowSurface(img->window)){
        printf("Unable to update the window surface !");
        printf("%s",SDL_GetError());
        return 0;
    }
    return 1;
    
}
int input_section(imgView* img){
         while(SDL_PollEvent(&img->event)){
            if(img->event.type==SDL_EVENT_QUIT){
                img->run=0;
            }
            if(img->event.type==SDL_EVENT_DROP_FILE){
          char* file=new_str(img->event.drop.data);
          const char *new=file;
          printf("%s",new);
        img->surface=SDL_LoadPNG(new);
        free(file);
        if(img->surface==NULL){
            printf("Could not load surface");
        }
        img->isDropped=1;
            }
            if(img->event.key.type==SDL_EVENT_KEY_DOWN ){
        if(img->event.key.key==SDLK_ESCAPE ){
          img->run=0  ;
        }
        
        }
        // if(img->event.type==SDL_EVENT_DROP_FILE){
        //     printf("A file has been dropped");
        //     printf("%s",img->event.drop.source);
        //     printf("%s",img->event.drop.data);
        // }
        if(img->event.type==SDL_EVENT_MOUSE_BUTTON_DOWN){
        if(img->event.button.clicks==3){//this are changes the background color when clicking the mouse left button thrice 
            srand(time(NULL));
            img->r=rand()%255;
            img->g=rand()%255;
            img->b=rand()%255;


            
        }
    }
    }
    return 1;
    
}
SDL_FRect* makeRect(imgView* img,int x,int y){
    SDL_FRect* rect=(SDL_FRect*)malloc(sizeof(SDL_FRect));
    push_sdl(img->new_stack,rect);
    rect->h=100;
    rect->w=20;
    rect->x=x;
    rect->y=y;
    SDL_SetRenderDrawColor(img->renderer,0,0,255,1);
    SDL_RenderRect(img->renderer,rect);
    SDL_RenderFillRect(img->renderer,rect);
    return rect;
}
int Garbage_collector(imgView* img){
    struct stack* s=img->new_stack;
    struct node* ptr=s->listhead;
    while(s->listhead!=NULL){
       SDL_FRect* temp= pop_sdl_Frect(s);
       free(temp);

    }
    return 1;

}
int blitPicture(imgView* img){
    for(int i=0;i<img->width;i++){
        for(int j=0;j<img->height;j++){
            if(!SDL_ReadSurfacePixel(img->surface,i,j,img->new_r,img->new_g,img->new_b,img->new_a)){
                printf("couldn't read pixel!!");
            }
            if(!SDL_WriteSurfacePixel(img->wSurface,i,j,*img->new_r,*img->new_g,*img->new_b,*img->new_a)){
                printf("could not write the pixel ");
            };

        }
    }
    return 1;

}
 char *new_str(const char *data){
    char* new;

    int len=strlen(data);
    new=malloc((len+1)*sizeof(char));
    strcpy(new,data);
    for(int i=0;i<len;i++){
        if(new[i]=='\\'){
            new[i]='/';
            }
    }
    
    return new;

    
}

