#ifndef SHOP_H_
#define SHOP_H_

typedef struct Player Player;

typedef enum ShopItem {
    WALKMAN,
    GUITAR,
    CELLPHONE
} ShopItem;

typedef struct Shop {
    ShopItem* shopItems;
    int* itemPrice;
} Shop;

void add_item(Player* player);

#endif // !SHOP_H_
