class Mouse : public sf::Sprite
{
public:
	int X, Y;
	int offsetX, offsetY;
private:
	virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
	}
};
