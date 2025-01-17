/*
Refactored by SPP DEV MDIC
Original Module from Conanhun
For Gwenpool 434 branch.
*/
#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "World.h"
#include "LFGMgr.h"
#include "Chat.h"
#include "Opcodes.h"

class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {
        if (sConfigMgr->GetBoolDefault("Login.Announcer.Enable", true))
        {
            if (player->GetTeam() == ALLIANCE)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ SPP Cata Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cff0026FF Alliance";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
            if (player->GetTeam() == HORDE)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ SPP Cata Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cffFF0000 Horde";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
            if (player->GetTeam() == TEAM_OTHER)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ SPP Cata Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cFF800080 Other";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }

        }
    }
};

void AddSC_announce_login()
{
    new announce_login;
}
