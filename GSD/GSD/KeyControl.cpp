#include "KeyControl.h"

int KeyControl::KeyInput(char key)
{
	switch (key)
	{
	case 'w' :
		return UP;
	case 's' :
		return DOWN;
	case 'a' :
		return LEFT;
	case 'd':
		return RIGHT;
	case ' ':
		return SELECT;
	}
}
