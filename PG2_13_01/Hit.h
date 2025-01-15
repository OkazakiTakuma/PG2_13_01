#pragma once
#include"Vector2.h"
/// <summary>
/// 円の当たり判定
/// </summary>
/// <param name="posA">1つ目の円の座標</param>
/// <param name="sizeA">1つ目の円の半径</param>
/// <param name="posB">2つ目の円の座標</param>
/// <param name="sizeB">2つ目の円の半径</param>
/// <returns>当たっているか</returns>
int Hit(Vector2 posA, Vector2 sizeA, Vector2 posB, Vector2 sizeB);
