#ifndef __NXCORE_DBENTITY__
#define __NXCORE_DBENTITY__

USING_NXCORE

#include <Define.h>
#include <PropsDefine.h>

#pragma pack(push, 1)

struct AccountInfo
{
    char account[ACCOUNT_NAME_SIZE+1];
    char password[PASSWORD_SIZE+1];
    char email[EMAIL_SIZE+1];
    char sign[PLAYER_SIGN_SIZE+1];
    playerid_t uid;
    uint32 state;
    
    AccountInfo() {
        bzero(this, sizeof(*this));
    }
};

struct VipProps
{
    uint32 BuySpCount;
    uint32 BuyPvpSpCount;
    uint32 NormalDunResetCount;
    uint32 EliteDunResetCount;
    uint32 ExpDunEnterCount;
    uint32 MoneyDunEnterCount;
    
    VipProps()
        : BuySpCount(0)
        , BuyPvpSpCount(0)
        , NormalDunResetCount(0)
        , EliteDunResetCount(0)
        , ExpDunEnterCount(0)
        , MoneyDunEnterCount(0)
        {}
};

struct PlayerBaseProperties
{
	char charName[PLAYER_NAME_SIZE]; 
	playerid_t uid;
	uint32 state; 
	uint32 money;
	uint32 gold;
    uint32 arenapoint;
    uint32 renown;
    uint32 soulstone;
    uint32 soulrefined;
    uint32 horsesoul;
    uint32 scroll;
    uint32 recharged;
	uint32 level;
    uint32 viplevel;
	uint32 exp;
	uint32 sp;
    uint32 pvpsp;
    uint32 addLead;
    
	uint32 createTime;
	uint32 loginTime;
	uint32 logoutTime;

    uint32 cardPkgSize;
    uint32 equipPkgSize;

    uint32 virgin;
    
	PlayerBaseProperties()
        : uid(0)
        , state(0)
        , money(0)
        , gold(0)
        , arenapoint(0)
        , soulstone(0)
        , soulrefined(0)
        , horsesoul(0)
        , scroll(0)
        , recharged(0)
        , level(1)
        , viplevel(0)
        , exp(0)
        , sp(10)
        , pvpsp(10)
        , addLead(0)
        , createTime(0)
        , loginTime(0)
        , logoutTime(0)
        , cardPkgSize(0)
        , equipPkgSize(0)
        , virgin(0)
	{
        bzero(charName, sizeof(charName));
	}

    void clear() {
        money        = 0;
        gold         = 0;
        recharged    = 0;
        arenapoint   = 0;
        soulstone    = 0;
        soulrefined  = 0;
        level        = 1;
        viplevel     = 0;
        exp          = 0;
        sp           = 0;
        pvpsp        = 0;
        addLead      = 0;
        
        cardPkgSize  = 50;
        equipPkgSize = 50;

        virgin       = 0;
    }
};

struct PropChange {
    Oper      oper;
    PropIndex propId;
    uint32    propValue;
    
    PropChange(Oper _oper, PropIndex _propId, uint32 _propValue)
        : oper(_oper)
        , propId(_propId)
        , propValue(_propValue)
        {}
};

struct PlayerCenteralBaseProps
{
	uint32 logoutTime;
};
struct PlayerCardProps
{
	uint16 pos[MAX_FIGHT_POS_COUNT];
	PlayerCardProps()
	{
		bzero(pos, sizeof(pos));
		pos[0] = 1;
	}
};

struct PlayerDailyGachaProps
{
	uint32 gachaAccTimes;
	uint32 dailyGachaTimes;
	uint32 accLoginDays;

	PlayerDailyGachaProps()
	: gachaAccTimes(0)
	, dailyGachaTimes(0)
	, accLoginDays(1)
	{

	}
};

struct CardProps 
{
	uint32 slot;       //槽位
	uint32 cardKey;    //卡牌ID
	uint32 level;      //等级
	uint32 exp;		   //经验
    uint32 costexp;    //吃卡经验
	uint32 state;      //状态
	uint32 skillLevel; //技能等级
    uint32 fightPos;   //阵法位置
    uint32 rank;       //卡牌品阶

	CardProps()
		: slot(0)
		, cardKey(0)
		, level(1)
		, exp(0)
        , costexp(0)
		, state(CardState_None)
		, skillLevel(1)
        , fightPos(0)
        , rank(1)
	{
	}

	uint32 getId() const
	{
		return slot;
	}
};

struct BattleDataProps
{
	uint16 len;
	char* data;
	BattleDataProps()
	: len(0)
	, data(NULL)
	{
	}
};

/**
 * 物品结构
 */
struct Item {
    uint16 id;
    uint16 count;
    uint16 slot;
    union {
        struct
        {
            uint16 level;
            uint16 rank;
            uint16 fightSlot;
            uint32 cost;
        } equip;
    };

    Item(uint16 _id = 0, uint16 _count = 0)
        : id(_id)
        , count(_count)
        , slot(0)
        {
            equip.level     = 1;
            equip.rank      = 1;
            equip.fightSlot = 0;
            equip.cost      = 0;
        }

    void clear() {
        bzero(this, sizeof(*this));
    }
};

/**
 * 背包变化记录
 */
struct ItemRecord {
    uint16 slot;
    Item itemprev;
    Item itemcurr;

    ItemRecord(uint16 _slot = 0)
        : slot(_slot) {
    }
};

/**
 * 奖励信息
 */
struct ItemReward {
    uint32 type;
    uint32 id;
    uint32 count;
    uint32 level;

    ItemReward()
        : type(0)
        , id(0)
        , count(0)
        , level(0)
        {}
};

struct InfoLoginZone
{
    playerid_t Uid;
    uint32 Zoneid;
    uint32 Rolenum;
    uint32 LastLoginTime;
    uint32 LastLogoutTime;
};

struct SceneProps
{
    uint32 LastSpCalcTime;     // 最后体力计算时间
    uint32 LastPvpSpCalcTime;  // 最后耐力计算时间
    uint32 ShopPayCount;       // 商城已经购买的次数
    uint32 ShopLastUpdateTime; // 商城最后自动刷新的时间.
    uint32 Power;              // 玩家总战力
    uint32 LeadCard;           // 队长卡牌ID
    uint32 LeadCardLv;         // 队长卡牌等级
    uint32 VipLevel;           // VIP等级
    uint32 Guide;              // 新手引导进度
    uint32 DailySp;            // 每日领体力标志
    struct {
        uint32 QuestScore;     // 任务总得分
        uint32 QuestScoreNeed; // 领取奖励需要得分
        uint32 QuestFinish;    // 任务链结束
    };
    uint32 LastDungeonAFTime;  // 最后扫荡时间
    uint32 LastOpTime;         // 最后操作时间
	uint32 LastChatTime;		//最后聊天时间
	uint32 FreeChatTimes;		//剩余免费聊天次数
    SceneProps()
    {
        LastSpCalcTime     = 0;
        LastPvpSpCalcTime  = 0;
        ShopPayCount       = 0;
        ShopLastUpdateTime = 0;
        Power              = 100;
        LeadCard           = 0;
        LeadCardLv         = 0;
        VipLevel           = 0;
        Guide              = 0;
        DailySp            = 0;
        QuestScore         = 0;
        QuestScoreNeed     = 0;
        QuestFinish        = 0;
        LastDungeonAFTime  = 0;
        LastOpTime         = 0;
		LastChatTime		= 0;
		FreeChatTimes		= 10;
    }
};

struct LotteryProps
{
    uint8  op;         // 抽奖类型
    uint32 freeCount;  // 免费次数
    uint32 time;       // 最后免费探索时间戳
    uint32 payCount;   // 付费次数
    int    opcnt;      // 抽卡的次数
    
    LotteryProps() {
        bzero(this, sizeof(*this));
    }
};

struct DungeonProgress
{
    uint32 bigLv;
    uint32 smallLv;
    uint32 EliteBigLv;
    uint32 EliteSmallLv;
    
    DungeonProgress() {
        bzero(this, sizeof(*this));
    }
};

struct DungeonState
{
    uint8 star;
    uint8 entercount;
    uint8 count;
    uint32 tick;
    
    DungeonState() {
        star       = 0;
        entercount = 0;
        count      = 0;
        tick       = 0;
    }
};
struct SlotEquip
{
    uint8 slot;
    uint8 equipType;
    uint16 equipID;
    uint16 level;
    uint16 rank;

    SlotEquip() {
        bzero(this, sizeof(*this));
    }
};

struct ShopItem
{
    uint16 slot;         // 位置
    uint16 id;           // 物品ID
    uint8  rand;         // 随机序号
    uint16 count;        // 堆叠个数
    uint32 oneprice;     // 物品单价
    uint8  type;         // 物品类型
    uint8  restype;      // 资源消耗类型
    uint8  state;        // 商品状态

    ShopItem()
        : slot(0)
        , id(0)
        , rand(0)
        , count(0)
        , oneprice(0)
        , type(0)
        , restype(0)
        , state(0)
        {}
};

struct QuestCond
{
    /**
     * 任务参数
     */
    union {
        struct {
            uint32 k1;
            uint32 k2;
            uint32 k3;
            uint32 k4;
        };
        char key[32];
    };

    QuestCond(uint32 _k1 = 0, uint32 _k2 = 0, uint32 _k3 = 0, uint32 _k4 = 0)
        : k1(_k1), k2(_k2), k3(_k3), k4(_k4)
    {}

    void set(uint32 _k1 = 0, uint32 _k2 = 0, uint32 _k3 = 0, uint32 _k4 = 0) {
        k1 = _k1;
        k2 = _k2;
        k3 = _k3;
        k4 = _k4;
    }
        
    uint32 hash() {
        uint32 ret = 0;
        for (int i = 0; i < 32; ++i) {
            int p = key[i];
            if (p != 0) {
                ret = (ret << 5) + p;
            }
        }
        return ret;
    }

    bool operator < (const QuestCond& cond) const {
        const uint32 *p = &k1;
        const uint32 *q = &cond.k1;

        for (int i = 0; i < 3; ++i) {
            if (*p != *q) return *p < *q;
            ++p;
            ++q;
        }
        return false;
    }

    bool operator > (const QuestCond& cond) const {
        return !(*this < cond);
    }
    
    bool operator == (const QuestCond& cond) const {
        return k1 == cond.k1 && k2 == cond.k2 && k3 == cond.k3 && k4 == cond.k4;
    }
};

struct ArenaProps
{
    uint32 Score;
    uint32 Lifeused;
    uint32 Lifecount;
    uint32 Rank;
    uint32 PrevRank;
    uint32 Reward;
    uint32 LastTime;

    ArenaProps()
        : Score(0)
        , Lifeused(0)
        , Lifecount(0)
        , Rank(0)
        , PrevRank(0)
        , Reward(1)
        , LastTime(0)
        {}
};

struct FriendProps
{
	uint16 dataLen;
	char* data;
	FriendProps()
		: dataLen(0)
		, data(NULL)
    {}
};

struct CardAttr {
    uint32 power;
    uint32 agile;
    uint32 wisdom;

    CardAttr() {
        bzero(this, sizeof(*this));
    }
};

struct DaySignProps {
    uint16 month;
    uint32 daySign;
    uint8  fill;
    uint8  reward;
    
    DaySignProps()
        : month(0)
        , daySign(0)
        , fill(0)
        , reward(0)
        {}
};

struct BabelProps {
    uint32 curr;
    uint64 best;
    uint32 lifeused;
    uint32 lifecount;
    uint32 resetused;
    uint32 resetcount;
    uint32 autofight;
    uint32 starttime;
    uint32 endtime;
    uint32 startlevel;

    BabelProps()
        : curr(0)
        , best(0)
        , lifeused(0)
        , lifecount(0)
        , resetused(0)
        , resetcount(0)
        , autofight(0)
        , starttime(0)
        , endtime(0)
        , startlevel(0)
        {}
};

struct HuntingProps
{
	uint8 stayPos;              //当前停留位置
	uint8 remainTimes;          //剩余投掷次数
	uint8 buyTimes;				//已经购买的次数
	uint32 restoreTime;			//恢复投掷次数时间

	struct HuntingMission
	{
		uint8 missionType;
		uint8 require;
		uint8 value;
		bool rewarded;

		HuntingMission()
			: missionType(0)
			, require(0)
			, value(0)
			, rewarded(false)
		{

		}
	}missions[3];           

	HuntingProps()
		: stayPos(0)
		, remainTimes(0)
		, buyTimes(0)
		, restoreTime(0)
	{

	}
};

struct MeltSlot
{
    uint16 slottype;
    uint16 slot;
};

#ifndef __SGROBOT__
struct QuestStatus {
    SET_CONTAINER(uint16) Rewarded;
    SET_CONTAINER(uint16) UnRewarded;
    MAP_CONTAINER(uint16, uint32) Actived;
};

const int RankTypeCount = 1;
struct RankData
{
    uint64 playerid;
    union {
        struct {
            /**
             * 变量定义的顺序不可更改
             */
            uint64 babel;
        };
        uint64 param[RankTypeCount];
    };
    
    RankData()
    {
        bzero(this, sizeof(*this));
    }
    
    uint32 index(uint64 *num)
    {
        uint64 dis = static_cast<uint64>(num - param);
        return static_cast<uint32>(dis / sizeof(uint64));
    }
};

struct RankInfo
{
    uint32 param[RankTypeCount];

    RankInfo() {
        bzero(this, sizeof(*this));
    }
};

typedef uint16                           slot;
typedef VECTOR_CONTAINER(Item)           vec_item;
typedef VECTOR_CONTAINER(Item)           vec_tradeout;
typedef VECTOR_CONTAINER(Item)           vec_tradein;
typedef VECTOR_CONTAINER(slot)           vec_slots;
struct ItemIndex
{
    uint32    count;
    vec_slots slots;
    ItemIndex()
    {
        count = 0;
    }
};
typedef MAP_CONTAINER(uint16, ItemIndex) map_index;
typedef SET_CONTAINER(slot)              set_slots;
typedef VECTOR_CONTAINER(ItemRecord)     vec_itemrecord;
typedef MAP_CONTAINER(BagType, vec_item) map_trade;
typedef MAP_CONTAINER(ResType, uint32)   map_res;

struct NewCard {
    uint16 cardKey;
    uint8  level;

    NewCard(uint16 _cardKey = 0, uint8 _lv = 1)
    : cardKey(_cardKey)
        , level(_lv) {}
};

typedef MAP_CONTAINER(uint8, uint32) map_cardprops;
typedef VECTOR_CONTAINER(NewCard) vec_card;

#endif
typedef uint8&                          RET;
typedef uint32&                         URET;                                  
#pragma pack(pop)

#endif//__NXCORE_DBENTITY__

