//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"



enum Window {
	WIDTH = 640,
	HEIGHT = 480
};



struct Miku
{
	float x;
	float y;
	float size_x;
	float size_y;
	float tsize_x;
	float tsize_y;
	//Texture texture[];

}miku;



//初期化
void Init()
{
	miku.x = 0;
	miku.y = 0;
	miku.size_x = 100;
	miku.size_y = 100;
	miku.tsize_x = 256;
	miku.tsize_y = 256;
	//miku.texture[index];

}



// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	int index = 0;

	Texture hatsune[3];

	hatsune[0] = Texture("res/miku1.png");
	hatsune[1] = Texture("res/miku2.png");
	hatsune[2] = Texture("res/miku3.png");
	
	Init();

	


	while (env.isOpen()) {

		//画像切り替え
		if (env.isPushKey('1'))
		{
			index = 0;
		}
		if (env.isPushKey('2'))
		{
			index = 1;
		}
		if (env.isPushKey('3'))
		{
			index = 2;
		}
		

		env.setupDraw();


		drawTextureBox(miku.x, miku.y, miku.size_x, miku.size_y, 0, 0, miku.tsize_x, miku.tsize_y, hatsune[index], Color(1, 1, 1));


		env.update();
	}
}
