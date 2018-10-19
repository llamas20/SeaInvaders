#include <SDL2/SDL.h>
#include <stdio.h>

const int WIDTH= 958;
const int HEIGHT= 536;

bool init();

bool load();

void close();

SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;

SDL_Surface* startscreen = NULL;

SDL_Surface* exitOut = NULL;

bool init(){
  bool success = true;

  if (SDL_Init (SDL_INIT_VIDEO)<0){
    success = false;
    printf("SDL could not be iniliazed, ERROR: %s\n", 
	   SDL_GetError());
  }
  else {
    window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
      printf("SDL could not be iniliazed, ERROR: %s\n",SDL_GetError());
      success = false;
    }
    else { screenSurface = SDL_GetWindowSurface(window);
  }
  }
    return success;
}

  bool media(){
    bool success = true;

    startscreen = SDL_LoadBMP("starting_screen.bmp");

     if (startscreen == NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false;
     }
   return success;
  }


  void close(){
    SDL_FreeSurface(startscreen);
    startscreen = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

 

  }

  int main(int argc, char* args[]){

    if(!init() ){
    printf("Failed to initialized!\n" );
    }
    else {
      if (!media() ){
	printf("Failed to load media \n" ); 
      }
      else{
	bool quit = false;

	SDL_Event e;

	while(!quit){
	  while( SDL_PollEvent( &e ) != 0 ){
	    if (e.type == SDL_QUIT){
	      quit = true;
	}
      }                      
	  SDL_BlitSurface( startscreen, NULL, screenSurface, NULL );                                                 
	  SDL_UpdateWindowSurface( window );
	}
      }
    }
    close();
    return 0;
  }
  /*
int main(int argc, char ** argv)
{
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;

  if (SDL_Init (SDL_INIT_VIDEO) < 0){
    printf("SDL could not be iniliazed, ERROR: %s\n", SDL_GetError());
  }
    else {

      window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
SDL_WINDOW_SHOWN);
      if ( window == NULL){
	printf("SDL could not be iniliazed, ERROR: %s\n", SDL_GetError());
      }
      else {
	screenSurface = SDL_GetWindowSurface(window);

      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF) );

      SDL_UpdateWindowSurface(window);

      SDL_Delay(2000);
    }
}

SDL_DestroyWindow(window);

SDL_Quit();

  return 0;
}
  */
