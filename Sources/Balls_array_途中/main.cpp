//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "lib/random.hpp"

enum Window {
	WIDTH = 512,
	HEIGHT = 512
};

enum 
{
	BALL_MAX = 8
};

struct Ball
{
	float x;
	float y;
	float size_x;
	float size_y;
	float r;
	float speed_x;
	float speed_y;
	Color color;
	bool active;

}ball[BALL_MAX];

Random random;
bool isMouseclick;

void Init()
{
	for (int i = 0; i < BALL_MAX; ++i){
		ball[i]. size_x = 10;
		ball[i]. size_y = 10;
		ball[i]. r = 10;
		bool active = false;
	}
}

// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);


	Init();
	

	


	while (env.isOpen()) {




		


		if (env.isPushButton(Mouse::LEFT))
		{
			isMouseclick = true;
		}
		
		for (int i = 0; i < BALL_MAX; ++i)
		{
			if (isMouseclick)
			{
				if (!ball[i].active)
				{
					ball[i].active = true;


					//マウスの位置に弾が出るようにできない下の書き方だとできない
					//ball[i].x = env.mousePosition.x();
					//ball[i].y = env.mousePosition.y();

					ball[i].speed_x = random.fromFirstToLast(1.0f, 3.0f);
					ball[i].speed_y = random.fromFirstToLast(2.0f, 5.0f);
					ball[i].color = Color(random.fromFirstToLast(0.0f, 1.0f), random.fromFirstToLast(0.0f, 1.0f), random.fromFirstToLast(0.0f, 1.0f));
				
					isMouseclick = false;

				}
			}
		}



		env.setupDraw();

		
			for (int i = 0; i < BALL_MAX; ++i)
			{
				if (ball[i].active)
				{
					drawFillCircle(ball[i].x, ball[i].y, ball[i].size_x, ball[i].size_y, 100, ball[i].color);
				}
			}
		
		env.update();
	}
}