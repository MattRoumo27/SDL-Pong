#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(float _x, float _y);

	virtual void update(double deltaTime);
	virtual void draw(struct SDL_Renderer* renderer) const;

	float getX() const;
	float getY() const;
	void setX(float _x);
	void setY(float _y);

private:
	double x;
	double y;
};

