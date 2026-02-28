
#include<stdio.h>
#include<SDL3/SDL.h>
#include<stdlib.h>

struct sdlapp{
SDL_Window* window;
SDL_Renderer* renderer;
 SDL_Surface* surface;
 SDL_Event events;
 SDL_FRect rect;

int run;
int a,b;


}app;
void render(struct sdlapp* a){
  
  a->rect.x=a->events.motion.x-300;
  a->rect.y=a->events.motion.y-100;

a->rect.h=100; 
a->rect.w=300;   
    
             if(!SDL_SetRenderDrawColor(a->renderer,163,123,145,1)){
        SDL_Log("Failed to Draw ");
     }
        SDL_RenderClear(a->renderer);
        SDL_SetRenderDrawColor(a->renderer,0,0,0,0);
        // SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x,a->events.motion.y);
        //  SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x+300.0f,a->events.motion.y);
        //   SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x,a->events.motion.y+100.0f);
        //    SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x+300.0f,a->events.motion.y+100.0f);
        // SDL_RenderClear(a->renderer);
         for(float i=0.0f;i<100.0f;i++){
            SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x-300,a->events.motion.y-100+i);
         }
         SDL_RenderRect(a->renderer,&a->rect);
         SDL_SetRenderDrawColor(a->renderer,255,255,255,255);
         for(float i=0.0f;i<300.0f;i++){
            SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x-300+i,a->events.motion.y-100);
         }
        
         if(!SDL_RenderPresent(a->renderer)){
        SDL_Log("Failed to render");
     }
    // a->rect.x=300;
    // a->rect.y=300;
    // SDL_Surface* windowSUrface=SDL_GetWindowSurface(a->window);
    // SDL_BlitSurface(a->surface,NULL,windowSUrface,NULL);
    // SDL_UpdateWindowSurface(a->window);
    
}
void input(){
    const bool* keystate=SDL_GetKeyboardState(NULL);
     if(SDL_PollEvent(&app.events)){
            if(app.events.type== SDL_EVENT_QUIT){
            app.run=0;
            }
            
            else if(keystate[ SDL_SCANCODE_ESCAPE]==true){//this make sure the programme closes when pressed escape

            app.run=0;                                          //This is a event handling type of thing where you take keys state and check if its being pressed or not
        
           
        }else if (app.events.button.clicks==2){//its a event that check how mny times mouse button has beenn clicked
            app.run=0;
        }
        // else if (events.type==SDL_EVENT_MOUSE_MOTION){

        //     SDL_Log("%f,%f\r",events.motion.x,events.motion.y);
        // }
        else if(app.events.type==SDL_EVENT_MOUSE_BUTTON_DOWN){
            if(app.events.button.button==SDL_BUTTON_LEFT  ){
                SDL_Log("The left button was pressed");
            }
        }
        }

    

}
void frameCount(struct sdlapp* a,int *fps,char(*fpS)[],Uint64 *tick,Uint64* tick2){
    if(*tick2>*(tick)+1000){//That gives the milisecond passed since the start of sdlinit
            // SDL_SetWindowTitle(a->window,)

           
            *tick=*tick2;//This is to make sure that the printing is happening each second
        sprintf(*(fpS),"%d",*fps);   
            // SDL_Log("%s",*(fpS));
           SDL_SetWindowTitle(a->window,*(fpS));
            *fps=0;//This is to reset the timer each second so we get only the value in that 1 sec timefframe
        }

}
void gameloop(struct sdlapp *a){
    int fps=0;
    char fpS[25];
    Uint64 lastTick=0;
    while(a->run){
        SDL_Delay(16.6);

       fps++;
        input();
        render(&app);
        Uint64 currentTick=SDL_GetTicks();
        frameCount(&app,&fps,&fpS,&lastTick,&currentTick);
    }
}
int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("failed");
        return 1;
    }
   app.run=1;
    
    app.window=SDL_CreateWindow("xman",1200,700,SDL_WINDOW_RESIZABLE|SDL_WINDOW_MOUSE_FOCUS);
    //  app.surface=SDL_LoadPNG("One.png.png");
     app.renderer=SDL_CreateRenderer(app.window,NULL);
    // SDL_Event events;
     SDL_KeyboardEvent key;
    const bool* keystate=SDL_GetKeyboardState(NULL);
    // int run=1;
    // int a,b;
    SDL_GetWindowSize(app.window, &app.a, &app.b);
    // printf("a,b:%d,%d",a,b);
    SDL_WarpMouseInWindow(app.window,app.a/2.00,app.b/2.00);//it centers the mouse inside the window 
   gameloop(&app);
//    input();



SDL_Quit();
    return 0;
}