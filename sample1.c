//
// MGL サンプル1 by みなつ
//

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MGL_IMPLEMENTATION
#include "MGL.h"

int main(int argc, char *argv[]) {
    // MGLを初期化
    MGL_Start();

    // 背景色を設定
    bgcolor(rgb(0, 0, 255));

    // スプライト用のページ(GRP2)を操作対象に
    gtarget(2);

    // GRP2を市松模様に初期化
    uint32_t c;
    for (int y = 0; y < GRP_H; y++) {
        for (int x = 0; x < GRP_W; x++) {
            unsigned char ichi = ((y / 16) + (x / 16)) % 2;
            c = (c + 1) % 256;
            int r = c;
            int g = (127 + ichi * 127);
            int b = c * 2;
            int a = (ichi * 128);
            gpset(x, y, rgba(r, g, b, a));
        }
    }

    // スプライトを作成
    spset(0, 0, 0, GRP_W, GRP_H);
    sphome(0, GRP_W / 2, GRP_H / 2);
    spset(1, 0, 0, GRP_W, GRP_H);
    sphome(1, GRP_W / 2, GRP_H / 2);

    // 2枚のスプライトを表示
    int x = 0, y = 0;   // 位置
    int vx = 2, vy = 1; // 移動速度
    float rot = 0;      // 回転角度（単位は度）
    float scale = 1;    // 拡大率
    float zoom = 0.005; // 拡大率の変化量
    while (1) {
        // スプライトの座標を更新
        x += vx;
        y += vy;

        // 画面端にぶつかったら速度を反転
        if (x <= 0 || x >= SW) {
            vx = -vx;
        }
        if (y <= 0 || y >= SH) {
            vy = -vy;
        }
        spofs(0, x, y, 0);

        // 回転してみる
        rot += 0.3;
        sprot(0, rot);

        // 大きくしたり小さくしたりしてみる
        scale = scale * (1.0 + zoom);
        if (scale > 10 || scale < 0.1) {
            zoom = -zoom;
        }
        spscale(0, scale, scale);

        // もう一枚のスプライトも表示してみる(SW,SHは画面のサイズです)
        spofs(1, SW - x, SH - y, 0);

        // VSync待ち
        vsync();
    }
}
