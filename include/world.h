#ifndef GUARD_WORLD_H
#define GUARD_WORLD_H

#define CHUNK_WIDTH 16  //Must be a power of two
#define CHUNK_HEIGHT 256

enum
{
	BLOCK_AIR,
	BLOCK_STONE,
	BLOCK_COBBLESTONE,
	BLOCK_SAND,
	BLOCK_SANDSTONE,
	BLOCK_DIRT,
	BLOCK_GRASS,
	BLOCK_WOOD,
    BLOCK_TREE,
    BLOCK_LEAVES,
    BLOCK_WATER,
    BLOCK_LAVA,
	BLOCK_BEDROCK,
	BLOCK_CLAY,
	BLOCK_BRICKS,
	BLOCK_CRAFT,
};

static char *blockNames[]=
{
	"Air",
    "Stone",
    "Cobblestone",
    "Sand",
    "Sandstone",
    "Dirt",
    "Grass Block",
    "Wood Planks",
    "Wood",
    "Leaves",
    "Water",
    "Lava",
    "Bedrock",
    "Clay",
    "Bricks",
    "Crafting Table",
};

#define BLOCK_IS_SOLID(b)   ((b) != BLOCK_AIR && (b) != BLOCK_WATER && (b) != BLOCK_LAVA)
#define BLOCK_IS_LIQUID(b)  ((b) != BLOCK_AIR)

struct Chunk
{
    bool active;
    int modificationIndex;
    int x;
    int z;
    void *dispList;
    size_t dispListSize;
    u8 blocks[CHUNK_WIDTH][CHUNK_HEIGHT][CHUNK_WIDTH];  //blocks[x][y][z]
};

struct BlockModification
{
    int x;
    int y;
    int z;
    int type;
};

struct ChunkModification
{
    int x;
    int z;
    struct BlockModification *modifiedBlocks;
    int modifiedBlocksCount;
};

struct SaveFile;

void world_init(void);
void world_load_textures(void);
void world_close(void);
struct Chunk *world_get_chunk(int x, int z);
struct Chunk *world_get_chunk_containing(float x, float z);
int world_to_chunk_coord(float x);
int world_to_block_coord(float x);
int world_get_block_at(float x, float y, float z);
void world_set_block(int x, int y, int z, int type);
void world_render_chunks_at(float x, float z);

#endif //GUARD_WORLD_H
