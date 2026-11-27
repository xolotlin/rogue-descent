#ifndef TILE_H
#define TILE_H

#include <cstdint>
#include <map>

enum class TileType {
    Empty = 0,
    Wall, 
    Platform,
    LockedDoor
};

class Tile {
public:
    int id;
    struct Pos {
        int x = 0, y = 0;
    } p; // Position of the Tile
    struct Color {
        uint8_t r,g,b,a;
    } c; // Color of the Tile

    TileType tileType; // Tile type
    // Access to sprite tileset

    float modifySpeed;
    float damage;

    bool isSolid;
    bool isSlippery;
    bool takeDamage;

    Tile(int id, Pos p, Color c, TileType type)
        : id(id), p(p), c(c), tileType(type) 
    {
        switch(tileType) {
            case TileType::Wall:
            case TileType::LockedDoor:
                isSolid = true;
                break;
            case TileType::Platform:
            case TileType::Empty:
            default:
                isSolid = false;
                break;
        }
    }

    ~Tile() = default;

    static Tile MakeWall(int id, Pos p) {
        return Tile(id, p, Color{100, 100, 100, 255}, TileType::Wall);
    }

    static Tile MakeEmpty(int id, Pos p) {
        return Tile(id, p, Color{0, 0, 0, 0}, TileType::Empty);
    }

    // getters
    int getId() const { return id; }
    inline int getID() const {return getId(); }

    Pos getPos() const { return p; }
    TileType getTileType() const { return tileType; }

    // setters
    void setId(int id) { this->id = id; }
    inline void setID(int id) {setId(id);}
    
    void setDamage(float damage) {this->damage = damage;}
    void setSpeed(float modifySpeed) {this->modifySpeed = modifySpeed;}
};

#endif // Tile_h