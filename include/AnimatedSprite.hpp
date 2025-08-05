#pragma once

#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Drawable, public sf::Transformable {
public:
  AnimatedSprite();

  void setTexture(const sf::Texture &texture);
  void setFrameSize(sf::Vector2i frameSize);
  void setNumFrames(std::size_t numFrames);
  void setDuration(float duration); // in seconds
  void setLooping(bool loop);

  void play();
  void stop();
  void reset();
  void update(float dt);

private:
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override;

  const sf::Texture *m_texture = nullptr;
  std::optional<sf::Sprite> m_sprite;

  sf::Vector2i m_frameSize;
  std::size_t m_numFrames = 0;
  float m_duration = 1.0f;
  float m_elapsed = 0.0f;
  std::size_t m_currentFrame = 0;
  bool m_isPlaying = true;
  bool m_isLooping = true;
};
