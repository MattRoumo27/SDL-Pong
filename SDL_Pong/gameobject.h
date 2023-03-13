#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(int _x, int _y);

	virtual void update();
	virtual void draw(struct SDL_Renderer* renderer) const;

	int getX() const;
	int getY() const;
	void setX(int _x);
	void setY(int _y);

private:
	int x;
	int y;
};

