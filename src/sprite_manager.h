#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "sprite.h"
#include <SFML/Graphics.hpp>

using SpriteID = size_t;

class SpriteManager {
public:
    sf::Texture& registerTexture(const std::string& filepath) {
        for (auto& value : textures) {
            if (value.first == filepath) {
                return value.second;
            }
        }
        std::string filepathCopy = filepath;
        sf::Texture texture(filepath);
        textures.emplace(filepathCopy, texture);
        return textures[filepathCopy];
    }

    template <typename... Args>
    SpriteID createSprite(Args&&... args) {
        sprites.emplace_back(std::forward<Args>(args)...);
        return sprites.size() - 1;
    }

    Sprite& getSprite(SpriteID id) { 
        return sprites[id];
    }


private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::vector<Sprite> sprites;
};

#endif  // SPRITE_MANAGER_H
