
#include<stdio.h>
#include<SDL3/SDL.h>
#include<stdlib.h>
#include<SDL3/SDL_stdinc.h>



struct sdlapp{
SDL_Window* window;
SDL_Renderer* renderer;
 SDL_Surface* surface;
 SDL_Event events;
 SDL_FRect rect;
 int n;
 int j;
 int state_For_Grid;
 struct particles{
    SDL_FPoint points[1000];

 };
 struct vector{
    float x1;
    float x2;
    float y1;
    float y2;

 };
 



int run;
int a,b;
int speed;
int motionState;


}app;
struct particles newP;
struct vector newV;
void grid();
void renderParticles(struct particles* p);
void update(struct particles* p){
    app.speed=5;
    
   p->points[0].x=app.events.motion.x;
    p->points[0].y=app.events.motion.y; 
    newV.x1=0.0f;
    newV.y1=10.0f;
    newV.x2=10.0f;
    newV.y2=0.0f;
    // renderParticles(p);
    
     for(int  i=0;i<1000;i++){
       p->points[i].x=SDL_rand(100)*1.0f+(app.j*1.0f);//its updating the location of the points 
        p->points[i].y=SDL_rand(100)*1.0f+(app.j*1.0f);
    
    
}

// if(app.motionState==1){
//        for(int  i=0;i<1000;i++){
//        p->points[i].x=SDL_rand(100)*1.0f+(app.j*1.0f);//its updating the location of the points 
//         p->points[i].y=SDL_rand(100)*1.0f+(app.j*1.0f);
// }

// }

 
   
    if(app.events.button.button==SDL_BUTTON_LEFT){
    app.state_For_Grid=1;
    }
    if(app.events.button.button==SDL_BUTTON_RIGHT){
        app.state_For_Grid=0;
    }

    if(app.state_For_Grid){
        grid();
    }
    
}


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
        
         for(float i=0.0f;i<100.0f;i++){
            SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x-300,a->events.motion.y-100+i);
         }
         SDL_RenderRect(a->renderer,&a->rect);
         SDL_SetRenderDrawColor(a->renderer,255,255,255,255);
         for(float i=0.0f;i<300.0f;i++){
            SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x-300+i,a->events.motion.y-100);
         }
         update(&newP);
         SDL_SetRenderDrawColor(a->renderer,0,0,0,0);
         SDL_RenderPoints(a->renderer,newP.points,1000);
        
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
    //    update(&newP);
        input();
        render(&app);
        Uint64 currentTick=SDL_GetTicks();
        frameCount(&app,&fps,&fpS,&lastTick,&currentTick);
        if(!app.motionState){
        if(a->j<500){
    a->j+=app.speed;
    }
}
    if(app.j>=500){
    app.motionState=1;

}
    if(app.motionState==1){
        if(a->j>0){
            a->j-=app.speed;
        }
    }
    
    }
    
}
int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("failed");
        return 1;
    }
   app.run=1;
   app.state_For_Grid=0;
   app.motionState=0;
    app.j=0;
    
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
    // update(&newP);
   gameloop(&app);
//    input();



SDL_Quit();
    return 0;
}
void grid(){
     for(int i=0;i<2200;i+=10 ){
        SDL_RenderLine(app.renderer,newV.x1+(i*1.0f),0.0f,newV.x2+(i*1.0f),2200);
        // newV.y1=newV.y1+(i*1.0f);
        // newV.x2=+(i*1.0f);
        // / newV.y2=+(i*1.0f);
        // newV.x1=+(i*1.0f);/
        // SDL_RenderLine(app.renderer,0,newV.y1,1200,newV.y2+(i*0.0f)); 

    }
    newV.x1=0.0f;
    newV.y1=10.0f;
    newV.x2=10.0f;
    newV.y2=0.0f;
    for(int i=0;i<2200;i+=10){
         SDL_RenderLine(app.renderer,0,newV.y1+(i*1.0f),2200,newV.y2+(i*1.0f));
    }
   
  

}
void renderParticles(struct particles* p){
       for(int j=0;j<500;j++){
    for(int  i=0;i<1000;i++){
       p->points[i].x=SDL_rand(100)*1.0f+(j*1.0f);//its updating the location of the points 
        p->points[i].y=SDL_rand(100)*1.0f;
    } 
}
}