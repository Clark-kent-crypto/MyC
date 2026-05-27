
#include<stdio.h>
#include<SDL3/SDL.h>
#include<stdlib.h>
#include<SDL3/SDL_stdinc.h>



struct sdlapp{
SDL_Window* window;//pointer to window where SDL_GetWindow return values is given
SDL_Renderer* renderer;//pointer to a renderer where you create a renderer
 SDL_Surface* surface;//pointer to a surface
 SDL_Event events;//event handles every event
 SDL_FRect rect;
 int n;
 int j;//its a variable that handles the change in x axis
 int yInc;//its similar to j but for y axis
 int xInc;//its same as j but i am too lazy to change it all the way so its still empty
 int state_for_revert;//does what its writter its just a variable that changes the state when to use revert
 int state_For_Grid;//again does what its writtern its a variable responsible to check when to render grid and when not to 0 as a flase state 1 as a true state
 Uint64 dT;//its delta time 
 struct particles{
    SDL_FPoint points[1000];

 };
 struct vector{
    float x1;
    float x2;
    float y1;//its to make the grid 
    float y2;

 };
 



int run;//responsible to maintain the gameloop
int a,b;//it has something to do with renderParticles fnctionn but i am too lazy to check what it does
int speed;//responsible to maintain the speed of motion in the initial animation 
int motionState;//maintain motion state 


}app;
struct particles newP;//particle system that take controls rectangles or squares
struct particles newp;//same as newP but for different one 
struct particles new2p;//   <<same as last>>
struct vector newV;
void app_init(struct sdlapp* a);
void grid();//declaration for grid function dont think i need to say anything what it does pretty selfexpanatory
void renderParticles(struct particles* p,int a,int b);//<<pretty selfexplanatory>> render particles
void revert(struct sdlapp* a);//revert the position back to initial position
void particleDeclare(struct particles* p);//it practically does nothing made it on a whim
void update(struct particles* p){//it updates the state every frame 
    app.speed=1*app.dT;
    

particleDeclare(p);
particleDeclare(&newp);
    newV.x1=0.0f;
    newV.y1=10.0f;
    newV.x2=10.0f;
    newV.y2=0.0f;
    renderParticles(p,25,87.5);
    renderParticles(&newp,100,50);
    renderParticles(&new2p,200,0);
    
//      for(int  i=0;i<1000;i++){
//        p->points[i].x=SDL_rand(100)*1.0f+(app.j*1.0f);//its updating the location of the points 
//         p->points[i].y=SDL_rand(100)*1.0f+(app.yInc*1.0f);
    
    
// }
  if(app.events.type==SDL_EVENT_KEY_DOWN ){
            if(app.events.key.key==SDLK_LCTRL){
                app.speed+=10;
                SDL_Log("ctrl was pressed");
            }
            else if(app.events.key.key==SDLK_D ){//codes below these all handles the movement of the object that you control
                app.j+=100;
            }
             else if(app.events.key.key==SDLK_A ){
                app.j-=100;
            }
            else if(app.events.key.key==SDLK_S){
                app.yInc+=100;
            }
              else if(app.events.key.key==SDLK_W){
                app.yInc-=100;
            }
        }



 
   
    if(app.events.button.button==SDL_BUTTON_LEFT){//chane the state to render the grid 
    app.state_For_Grid=1;
    }
    if(app.events.button.button==SDL_BUTTON_RIGHT){//change the state for derendering the grid
        app.state_For_Grid=0;
    }

    if(app.state_For_Grid){//render the grid
        grid();
    }
    SDL_RenderPoints(app.renderer,newP.points,1000);
    
}


void render(struct sdlapp* a){//this is our main render function 
    

  
  a->rect.x=a->events.motion.x-300;
  a->rect.y=a->events.motion.y-100;

a->rect.h=100; 
a->rect.w=300;   
    
             if(!SDL_SetRenderDrawColor(a->renderer,163,123,145,1)){
        SDL_Log("Failed to Draw ");
     }
        SDL_RenderClear(a->renderer);
        SDL_SetRenderDrawColor(a->renderer,0,0,0,0);
        
        //  for(float i=0.0f;i<100.0f;i++){
        //     SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x-300,a->events.motion.y-100+i);
        //  }
        //  SDL_RenderRect(a->renderer,&a->rect);
         SDL_SetRenderDrawColor(a->renderer,255,255,255,255);
        //  for(float i=0.0f;i<300.0f;i++){
        //     SDL_RenderLine(a->renderer,0.0f,0.0f,a->events.motion.x-300+i,a->events.motion.y-100);
        //  }
         
         
         SDL_SetRenderDrawColor(a->renderer,0,0,0,0);
        //  SDL_RenderPoints(a->renderer,newP.points,1000);
        update(&newP);
        SDL_SetRenderDrawColor(a->renderer,210,210,210,210);
         SDL_RenderPoints(a->renderer,newp.points,1000);
         SDL_SetRenderDrawColor(a->renderer,250,250,250,250);
         SDL_RenderPoints(a->renderer,new2p.points,1000);
        
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
void gameloop(struct sdlapp *a,struct particles* p){
    int fps=0;
    char fpS[25];
    Uint64 lastTick=0;
     Uint64 lasttick=0;
    while(a->run){
        // SDL_Delay(16.6);

       fps++;
    //    update(&newP);
        input();
        render(&app);
        Uint64 currentTick=SDL_GetTicks();
        app.dT=currentTick-lasttick;
        
        frameCount(&app,&fps,&fpS,&lastTick,&currentTick);
        lasttick=currentTick;
        if(!app.motionState){//this code only runs when the motion state is 0 
        if(a->j<600||newP.points[1000].y<600.0f){// it handles the movement of x
    a->j+=app.speed;
    
    }
     if(a->yInc<600||newP.points[1000].y<600.0f){//it handles the movement of y
    
    a->yInc+=app.speed;
    }
}
    if(app.j>=500){//it changes the motion state to 1
    app.motionState=1;
   

}
// else if(newP.points[1000].x<600){
//     app.motionState=0;
// }

if(a->events.type==SDL_EVENT_KEY_DOWN){//if pressed right control button the object will return to its initial position
if(a->events.key.key==SDLK_RCTRL){
a->state_for_revert=1;
}
}
if(a->state_for_revert){
    revert(&app);
}
if(app.j<=0&&app.yInc<=0){
    a->state_for_revert=0;//it stops revert once its back to its old position
}





}
    



}


int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("failed");
        return 1;
    }
    app_init(&app);//initializes a lot of app struct variables at the start , creates a window and a renderer

//     SDL_Event events;
     SDL_KeyboardEvent key;
    const bool* keystate=SDL_GetKeyboardState(NULL);
    // int run=1;
    // int a,b;
    SDL_GetWindowSize(app.window, &app.a, &app.b);
    // printf("a,b:%d,%d",a,b);
    SDL_WarpMouseInWindow(app.window,app.a/2.00,app.b/2.00);//it centers the mouse inside the window 
    // update(&newP);
   gameloop(&app,&newP);
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
void renderParticles(struct particles* p,int a,int b){
       for(int j=0;j<500;j++){
    for(int  i=0;i<1000;i++){
       p->points[i].x=SDL_rand(a)*1.0f+(app.j*1.0f)+(b*1.0f);//its updating the location of the points 
        p->points[i].y=SDL_rand(a)*1.0f+(app.yInc*1.0f)+(b*1.0f);
    } 
}
}
void revert(struct sdlapp* a){
     if(app.motionState==1){
        if(a->j>0){
            a->j-=app.speed;
        }
        if(a->yInc>0){
            a->yInc-=app.speed;
        }
    }

}
void particleDeclare(struct particles* p){
    p->points[0].x=app.events.motion.x;
    p->points[0].y=app.events.motion.y;

}
void app_init(struct sdlapp* a){
      app.run=1;
   app.state_For_Grid=0;
   app.state_for_revert=0;
   app.motionState=0;
    app.j=0;
    app.yInc=0;
    app.xInc=0;
    
    app.window=SDL_CreateWindow("xman",1200,700,SDL_WINDOW_RESIZABLE|SDL_WINDOW_MOUSE_FOCUS);
    //  app.surface=SDL_LoadPNG("One.png.png");
     app.renderer=SDL_CreateRenderer(app.window,NULL);

}