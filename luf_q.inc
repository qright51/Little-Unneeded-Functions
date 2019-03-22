//by qRighT
#include <a_samp>

stock bool:IsCoordNearCoord(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:radius)
{
	x1=floatabs(x1-x2);
	y1=floatabs(y1-y2);
	z1=floatabs(z1-z2);
	return (x1*x1) + (y1*y1) + (z1*z1) <= radius*radius;
}

stock SetPlayerMainStats(playerid, Float:health, Float:armour, money)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(health<100000.0 || health>100000.0 || armour<0.0 || armour>1000.0)
	    return 0;
	    
	if(money<(-99999999) || money>99999999)
	    return 0;
	    
	SetPlayerHealth(playerid, health);
	SetPlayerArmour(playerid, armour);
	GivePlayerMoney(playerid, money);
	return 1;
}

stock GetPlayerMainStats(playerid, &Float:health, &Float:armour, &money)
{
	if(!IsPlayerConnected(playerid)) return 0;
	GetPlayerHealth(playerid,health);
	GetPlayerArmour(playerid,armour);
	money = GetPlayerMoney(playerid);
	return 1;
}

//-------------------------------------

stock Kill(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	SetPlayerHealth(playerid,-1000.0);
	return 1;
}

stock KillAllPlayers()
{
	for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
			SetPlayerHealth(i,-100.0);
	return 1;
}

//-----------------------------------

stock KickPlayer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	SetTimerEx("luf_q_killtimer587",1000,false,"i",playerid);
	return 1;
}

forward luf_q_killtimer587(playerid);
public luf_q_killtimer587(playerid)
	Kick(playerid);

stock BanPlayer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	SetTimerEx("luf_q_bantimer156",1000,false,"i",playerid);
	return 1;
}

forward luf_q_bantimer156(playerid);
public luf_q_bantimer156(playerid)
	Ban(playerid);

//----------------------------------------------

stock KickPlayerEx(playerid, color, const reason[])
{
	if(!IsPlayerConnected(playerid)) return 0;
	SendClientMessage(playerid, color, reason);
	SetTimerEx("luf_q_killtimer134",1000,false,"i",playerid);
	return 1;
}

forward luf_q_killtimer134(playerid);
public luf_q_killtimer134(playerid)
	Kick(playerid);

stock BanPlayerEx(playerid, color, const reason[])
{
	if(!IsPlayerConnected(playerid)) return 0;
	SendClientMessage(playerid, color, reason);
	SetTimerEx("luf_q_bantimer675",1000,false,"i",playerid);
	return 1;
}

forward luf_q_bantimer675(playerid);
public luf_q_bantimer675(playerid)
	Ban(playerid);

//--------------------------------------------

stock GiveMoneyToAll(money)
{
	for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
			GivePlayerMoney(i,money);
	return 1;
}
//--------------------------------------------

stock bool:IsPlayerNearPlayer(playerid, targetid, Float:radius)
{
	if(!IsPlayerConnected(targetid)||!IsPlayerConnected(playerid)) return 0;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(targetid,x,y,z);
	return IsPlayerInRangeOfPoint(playerid,radius,x,y,z);
}

stock SetHealthToAll(Float:health)
{
	for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
			SetPlayerHealth(i,health);
	return 1;
}