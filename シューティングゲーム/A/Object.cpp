#include "stdafx.h"
#include"DxLib.h"
#include"Object.h"

void ChackHitCircle(CObject *obj1, CObject *obj2)
{
	//‚â‚Á‚Ä‚é‚±‚Æ‚Í‚±‚ê
	//((obj1.pos.x - obj2.pos.x)*(obj1.pos.x - obj2.pos.x) + (obj1.pos.y - obj2.pos.y)*(obj1.pos.y - obj2.pos.y))
	float distance = VSquareSize(VSub(*obj1->GetPos(), *obj2->GetPos()));
	float range = (obj1->GetRange() + obj2->GetRange())*(obj1->GetRange() + obj2->GetRange());
	
	//HIT
	if (distance < range)
	{
		obj1->HitAction();
		obj2->HitAction();
	}

	
}