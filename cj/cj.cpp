#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#define FPS 60
#define IMG_PATH "cj_pixelated.png"
#define IMG_PATH2 "background.png"


//position and width and height
SDL_Rect windowRect = { 200, 200, 800, 500 };

//window thingies
SDL_Window* window;
SDL_Renderer* renderer;


//texture thingies
SDL_Texture* background;
SDL_Texture* coco_text;

//music
Mix_Music *music;


//initializing functions
bool InitEverything();
bool InitSDL();
bool CreateWindow();
bool CreateRenderer();
bool InitAudio ();
void SetupRenderer();
void Render();

int main (int argc, char* args[]){
	SDL_Rect backgrounds;
	backgrounds.x = 71;
	backgrounds.y = 0;
	backgrounds.w = 71;
	backgrounds.h = 54;	
	

	SDL_Rect coco_rect[11];
	int i = 0;
	
	//different rectangles
	for(i; i < 6; ++i){
		coco_rect[i].x = 286;
		coco_rect[i].y = 132 + i*4;
		coco_rect[i].w = 228;
		coco_rect[i].h = 237;			
	}
	int n = i - 1;
	
	for(i; i < 12; ++i){
		coco_rect[i].x = 286;
		coco_rect[i].y = 132 +4 * 2 * n - i*4;
		coco_rect[i].w = 228;
		coco_rect[i].h = 237;

	}
	
	
	i = 0;



	InitEverything();
	coco_text = IMG_LoadTexture(renderer, IMG_PATH);
	background = IMG_LoadTexture(renderer, IMG_PATH2);
	music = Mix_LoadMUS( "coco.mp3");
	//for debugging 
	//std::ofstream io;
	
while (1){
	SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
			 else if( e.key.keysym.sym == SDLK_9 )
                {	
                    //If there is no music playing
                    if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                        if( Mix_PlayMusic( music, -1 ) == -1 )
                        {
                            return 1;
                        }    
                    }
					else
                    {
                        //If the music is paused
                        if( Mix_PausedMusic() == 1 )
                        {
                            //Resume the music
                            Mix_ResumeMusic();
                        }
                        //If the music is playing
                        else
                        {
                            //Pause the music
                            Mix_PauseMusic();
                        }
                    }
                }
		}
	int counter = 0;
    int looptime = SDL_GetTicks();
	
/* for debugging
if (i/11 <= 11 && n != 1){
	
	std::cout <<"\ni: " << i/11 << "\n";
	std::cout <<"x: " << coco_rect[i/11].x << std::endl;
	std::cout <<"y: " << coco_rect[i/11].y << std::endl;
	std::cout <<"w: " << coco_rect[i/11].w << std::endl;
	std::cout <<"h: " << coco_rect[i/11].h << std::endl;
	
	io.open ("debug.txt", std::ios::out | std::ios::app);
	io <<"\ni: " << i/11 << "\n";
	io <<"x: " << coco_rect[i/11].x << std::endl;
	io <<"y: " << coco_rect[i/11].y << std::endl;
	io <<"w: " << coco_rect[i/11].w << std::endl;
	io <<"h: " << coco_rect[i/11].h << std::endl;
}
io.close();
*/
	
	if (SDL_GetTicks() - looptime < 1000/FPS)
            SDL_Delay(1000/FPS - (SDL_GetTicks() - looptime));
        looptime = SDL_GetTicks();
		
	SDL_RenderClear( renderer );
	SDL_RenderCopy(renderer, background, &backgrounds, NULL);
	SDL_RenderCopy(renderer, coco_text, NULL, &coco_rect[i/20]);
	
	
	++i;
	if(i/20 >= 12 ) {
		i = 0;
		n = 1;
	}
	SDL_RenderPresent (renderer );
	
}
	SDL_DestroyTexture(coco_text);
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeMusic (music);
	
	window = NULL;
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
	Mix_CloseAudio();
	
	return 0;
}

bool InitEverything() {
	InitSDL();
	CreateWindow();
	CreateRenderer();
	SetupRenderer();
	InitAudio();

	return true;
}


bool InitSDL() {
	SDL_Init( SDL_INIT_EVERYTHING );
	if ( SDL_Init ( SDL_INIT_EVERYTHING ) == -1 ){
		std::cout << "Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}
}

bool CreateWindow() {
	window = SDL_CreateWindow ("bruh", windowRect.x, windowRect.y, windowRect.w, windowRect.h, SDL_WINDOW_RESIZABLE );
	if (window == NULL ) {
		std::cout << "failed to create window : " << SDL_GetError() << std::endl;
		return false;
	}
}

bool CreateRenderer() {
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL ){
		std::cout << "Failed to create renderer : " << SDL_GetError() << std::endl;
		return false;
	}
}

void SetupRenderer() {
	SDL_RenderSetLogicalSize (renderer, windowRect.w, windowRect.h  );
}

bool InitAudio(){
	Mix_Init(MIX_INIT_MP3);
	
	Mix_OpenAudio ( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;    
    }
}