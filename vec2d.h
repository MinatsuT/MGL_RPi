//
// Vector2D Library by Minatsu
//
#ifndef __VEC2D_H_
#define __VEC2D_H_

#include <stdio.h>

#include <math.h>

typedef struct {
    float x;
    float y;
} vec2d;

static vec2d v2add(vec2d a, vec2d b);
static vec2d v2sub(vec2d a, vec2d b);
static vec2d v2mul(vec2d a, float n);
static vec2d v2div(vec2d a, float n);
static float v2dist(vec2d a);
static vec2d v2norm(vec2d a);
static float v2dot(vec2d a, vec2d b);
static vec2d v2rot(vec2d a, float th);
static void print_v2(vec2d a);

vec2d v2add(vec2d a, vec2d b) {
    vec2d ret = {a.x + b.x, a.y + b.y};
    return ret;
}

vec2d v2sub(vec2d a, vec2d b) {
    vec2d ret = {a.x - b.x, a.y - b.y};
    return ret;
}

vec2d v2mul(vec2d a, float n) {
    vec2d ret = {a.x * n, a.y * n};
    return ret;
}

vec2d v2div(vec2d a, float n) {
    vec2d ret = {a.x / n, a.y / n};
    return ret;
}

float v2dist(vec2d a) {
    return sqrtf(a.x * a.x + a.y * a.y);
}

vec2d v2norm(vec2d a) {
    return v2div(a, v2dist(a));
}

float v2dot(vec2d a, vec2d b) {
    return a.x * b.x + a.y * b.y;
}

vec2d v2rot(vec2d a, float th) {
    float c = cos(th);
    float s = sin(th);
    vec2d ret = {a.x * c - a.y * s, a.x * s + a.y * c};
    return ret;
}

vec2d v2rotd(vec2d a, float deg) {
    return v2rot(a, deg * M_PI / 180.0);
}

void print_v2(vec2d a) {
    printf("(%f,%f)", a.x, a.y);
}

#endif
