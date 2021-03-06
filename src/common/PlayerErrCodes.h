#ifndef PLAYER_ERROR_CODES_H
#define PLAYER_ERROR_CODES_H

#include "Define.h"
/**
 * 服务端将非常多的常量定义在Define.h中，不方便查找和维护，
 * 受MangOs风格的启发，将常量按功能定义
 * 
 * 玩家卡牌常量、操作返回码等
 *
 * OrangE 2014.5.3
 */
enum
{
    CARD_ERR_OK                       = 0,
    CARD_ERR_MAIN_CARD_NOT_EXIST      = 1, // 主卡牌不存在
    CARD_ERR_CANT_COST_FIGHTING_CARD  = 2, // 不能吞噬出战卡牌
    CARD_ERR_CANT_COST_MAINCARD       = 3, // 不能吞噬主卡
    CARD_ERR_CANT_HIGHER_THAN_PLAYER  = 4, // 等级不能高于君主等级
    CARD_ERR_CARD_IS_FULL_LEVEL       = 5, // 卡牌已经满级，不能继续升级
    CARD_ERR_LESS_MONEY_FOR_LEVELUP   = 6, // 没有足够的金钱升级卡牌
    CARD_ERR_COST_CARD_NOT_EXIST      = 7, // 被吞噬卡不存在
    CARD_ERR_LESS_MONEY_FOR_RANKUP    = 8, // 没有足够的铜钱升阶卡牌
    CARD_ERR_COST_DIFF_FROM_MAIN      = 9, // 消耗卡与主卡不同名
    CARD_ERR_LESS_CARD_FOR_RANKUP     = 10,// 消耗卡数量不够升阶
    CARD_ERR_CANT_RANKUP_IN_CURRRANK  = 11,// 当前品阶不能继续升阶
    CARD_ERR_LESS_ITEM_FOR_RANKUP     = 12,// 没有足够的物品升阶
    CARD_ERR_SOURCE_CARD_NOT_EXIST    = 13,// 卡牌移动源卡牌不存在
    CARD_ERR_NOT_ENOUGH_FIGHT_CARD    = 14,// 卡牌移动没有足够的出战卡
    CARD_ERR_BAG_SLOT_EMPTY           = 15,// 背包指定槽位是空的
    CARD_ERR_EQUIP_SLOT_EMPTY         = 16,// 背包指定装备槽位是空的
    CARD_ERR_EQUIP_BAG_FULL           = 17,// 装备背包已满
    CARD_ERR_EQUIPLV_EQ_PLAYERLV      = 18,// 装备等级已经等于玩家等级
    CARD_ERR_LESS_MONEY_FOR_EQLVUP    = 19,// 没有足够的铜钱用于装备升级
    CARD_ERR_EQUIP_NOT_USED           = 20,// 装备没有穿在身上
    CARD_ERR_LESS_MONEY_ONE_LOTTERY   = 21,// 单次抽铜钱不足
    CARD_ERR_LESS_MONEY_TEN_LOTTERY   = 22,// 十次抽铜钱不足
    CARD_ERR_LESS_GOLD_ONE_LOTTERY    = 23,// 单次抽元宝不足
    CARD_ERR_LESS_GOLD_TEN_LOTTERY    = 24,// 十次抽元宝不足
    CARD_ERR_LESS_ITEM_ONE_LOTTERY    = 25,// 单次抽道具不足
    CARD_ERR_NO_CONFIG_FOR_LOTTERY    = 26,// 十次抽道具不足
    CARD_ERR_TARGET_SLOT_NOT_EXIST    = 27,// 目标槽位不存在
    CARD_ERR_CARD_BAG_FULL            = 28,// 卡牌背包已满
    CARD_ERR_THIS_CARDKEY_IS_FIGHTING = 29,// 已经存在同名出战卡牌
    CARD_ERR_CANT_REMOVE_LEADCARD     = 30,// 队长卡牌不能被移除
    CARD_ERR_LEADPOINT_NOT_ENOUGH     = 31,// 领导力不足
};

enum
{
    ERROR_CODE_LOGIN_FAILED              = 1,  // 登录失败
    ERROR_CODE_SELLITEM_OUT_OF_RANGE     = 50, // 售卖物品槽位超出范围
    ERROR_CODE_SELLITEM_IS_EMPTY         = 51, // 该槽位没有物品
    ERROR_CODE_SELLITEM_EQUIPED          = 52, // 物品已经装备，不能售卖
    ERROR_CODE_SELLITEM_NOTEXIST         = 53, // 物品不存在
    ERROR_CODE_SELLITEM_CANT_SELL        = 54, // 该物品不可售卖，价格为0
    ERROR_CODE_SHOP_LESS_GOLD_UPDATE     = 55, // 没有足够的元宝刷新商店
    ERROR_CODE_SHOP_LESS_GOLD_BUYITEM    = 56, // 没有足够的元宝购买商店物品
    ERROR_CODE_SHOP_LESS_MONEY_BUYITEM   = 57, // 没有足够的铜钱购买商店物品
    ERROR_CODE_SHOP_ITEM_EMPTY           = 58, // 物品已经售完
    ERROR_CODE_PLOT_NOT_CORRECT          = 59, // 剧情进度不正确
    ERROR_CODE_PRODUCE_SLOT_OUT_OF_RANGE = 60, // 合成槽位超出范围
    ERROR_CODE_PRODUCE_ITEM_EMPTY        = 61, // 指定槽位没有材料
    ERROR_CODE_PRODUCE_NONE_CONFIG       = 62, // 没有对应的合成配方
    ERROR_CODE_PRODUCE_CONFIG_ERROR      = 63, // 指定槽位材料不能合成所需物品
    ERROR_CODE_PRODUCE_LESS_CHIPS        = 64, // 材料数量不足
    ERROR_CODE_PRODUCE_LESS_MONEY        = 65, // 铜钱不足
    ERROR_CODE_QUEST_REWARD_NOT_EXIST    = 66, // 任务奖励不存在
    ERROR_CODE_USE_BOX_CONFIG_NOT_EXIST  = 67, // 对应配置不存在
    ERROR_CODE_USE_BOX_FAILED            = 68, // 背包满或者钥匙不存在
    ERROR_CODE_USE_SUNDRY_FAILED         = 69, // 使用道具失败
    ERROR_CODE_EQUIP_BAG_FULL            = 70, // 装备背包已满
    ERROR_CODE_CARD_BAG_FULL             = 71, // 卡牌背包已满
	ERROR_CODE_CHAT_NONPLAYER			 = 72, // 私聊对象玩家不存在
};

enum
{
    DUNGEON_ERR_UNKNOW             = 0, // 位置错误
    DUNGEON_ERR_NOT_ENOUGH_SP      = 101, // 体力不足
    DUNGEON_ERR_SCENE_NOT_EXIST    = 102, // 场景不存在
    DUNGEON_ERR_PREV_NOT_PASSED    = 103, // 前一个副本没有通关
    DUNGEON_COUNT_NOT_ENOUGH       = 104, // 进入次数不足
    DUNGEON_ERR_SCENE_LOCKED       = 105, // 副本未开放
    DUNGEON_ERR_LEVEL_TOO_LOW      = 106, // 等级过低
    DUNGEON_ERR_TIME_LOCKINT       = 107, // 副本处于未开放日期
    DUNGEON_ERR_WEEK_LOCKINT       = 108, // 副本今天不开放X
    DUNGEON_ERR_CLOCK_LOCKING      = 109, // 周循环副本处于未开放时间点
    DUNGEON_ERR_DUNGEON_INCD       = 110, // 副本处于扫荡CD之中
    DUNGEON_ERR_DUNGEON_NOT_FINISH = 111, // 副本没有通关，不能扫荡
    DUNGEON_ERR_CARD_BAG_IS_FULL   = 112, // 卡牌背包已满，不能进行战斗
    DUNGEON_ERR_EQUIP_BAG_IS_FULL  = 113, // 装备背包已满，不能进行战斗
};

enum
{
    DR_TYPE_NOT_EXIST        = 151, // 奖励类型不存在
    DR_BIGLV_NOT_EXIST       = 152, // 大关卡不存在
    DR_STAR_NOT_ENOUGH       = 153, // 星星不足
    DR_GOT_REWARD_BEFORE     = 154, // 以前领过该奖励
    DR_REWARD_CONF_NOT_EXIST = 155, // 奖励配置不存在
    DR_BAG_IS_FULL           = 156, // 背包已满
    DR_LESS_LEVEL            = 157, // 等级不足以进入
    DR_LESS_ENTER_COUNT      = 158  // 没有足够的进入次数
};

enum
{
    BABEL_NOT_EXIST         = 180, // 通天塔不存在
    BABEL_NON_LIFE          = 181, // 通天塔，没有足够的挑战次数
    BABEL_NON_RESET         = 182, // 通天塔，没有足够的重置次数
    BABEL_LESSGOLD_BUYRESET = 183, // 通天塔，没有足够的元宝购买重置次数
    BABEL_LESSGOLD_BUYLIFE  = 184, // 通天塔，没有足够的元宝购买挑战次数
    BABEL_ALREADY_INTOP     = 185, // 通天塔，已经是最高层，不能扫荡
    BABEL_BUYRESET_LIMIT    = 186, // 已经不能购买更多的重置次数
    BABEL_LESS_GOLD_AUTO    = 187, // 没有足够的元宝进行无CD扫荡
};

enum
{
    ARENA_CANT_FIND_ENERMY = 200,  // 竞技场，无效的对手
    ARENA_NOT_ENOUGH_LIFE  = 201,  // 竞技场，进入次数不足
    ARENA_IN_CD            = 202,  // 竞技场，CD
    ARENA_BUY_LIFE_LIMITED = 203,  // 竞技场，购买次数到达上限
    ARENA_BUY_LESS_GOLD    = 204,  // 竞技场，没有足够的元宝购买进入次数
    ARENA_REWARD_NOTEXIST  = 205,  // 竞技场，奖励已经被领取
    ARENA_REWARD_UNQ       = 206,  // 竞技场，没有达到领取排名的要求
    ARENA_BAG_Full         = 207,  // 竞技场，背包满，无法领取奖励
    ARENA_CANT_FIGHT_SELF  = 210,  // 竞技场，不能挑战自己
};

enum
{
    QUEST_BAG_FULL  = 300, // 成就系统，背包已满，不能领取奖励
};

enum
{
    DAY_SIGN_NOT_ENOUGH_GOLD = 400,
};

enum
{
    SHOP_NORMAL_BUY_COUNT_LIMIT  = 450, // 普通商城，物品购买次数超过上限
    SHOP_NORMAL_LESS_GOLD        = 451, // 普通商城，没有足够的元宝购买物品
    SHOP_NORMAL_RUCKSACK_FULL    = 452, // 普通商城，背包已满不能购买
    SHOP_NORMAL_BUY_LIMIT        = 453, // 普通商城，不能突破终生购买次数限制
};

enum
{
    VIP_LESS_GOLD_RESET_NORMAL  = 500,  // 没有足够的元宝重置普通副本
    VIP_LESS_GOLD_RESET_ELITE   = 501,  // 没有足够的元宝重置精英副本
};

enum
{
    MELT_CARD_IN_FIGHTING    = 600, // 出战卡牌不能被炼化
    MELT_CARD_RANKED         = 601, // 升阶的卡牌不能被炼化
    MELT_CARD_LOW_QUALITY    = 602, // 卡牌品质太低
    MELT_CARD_NONMELT        = 602, // 卡牌不能被炼化
    MELT_EQUIP_NOTEXIST      = 603, // 该槽位没有装备
    MELT_EQUIP_TAKING        = 604, // 已经穿上的装备不能被炼化
    MELT_EQUIP_NONMELT       = 605, // 该装备天生不能被炼化
    REBORN_BAG_ISFULL        = 606, // 背包已满，不能进行卡牌重生
    MELT_CARD_LESS_GOLD      = 606, // 元宝不足，不能进行卡牌重生
    MELT_EQUIP_LESS_GOLD     = 607, // 元宝不足，不能进行卡牌重生
};

enum
{
	OFFICER_PLAYER_NOT_EXIST			= 700, // 无效的目标玩家
	OFFICER_PLAYER_LESS_LEVEL			= 701, // 等钱玩家等级不够晋升
	OFFICER_PLAYER_FIGHTED				= 702, // 已经对该玩家权斗过
	OFFICER_PLAYER_AWARDED				= 703, // 已经对该玩家赏赐过
	OFFICER_PLAYER_WORSHIPED			= 704, // 已经对该玩家俯首过
	OFFICER_PLAYER_PROTECT_CD			= 705, // 晋升/降级挑战保护时间中
	OFFICER_PLAYER_FAIL_CD				= 706, // 晋升挑战失败CD时间中
	OFFICER_PLAYER_NOT_IN_LIST			= 707, // 玩家已经不在当前的官阶中
	OFFICER_PLAYER_DEMOTE_CD			= 708, // 贬职的CD时间中
};

enum
{
    MAIL_NOT_EXIST = 800, // 邮件不存在
    MAIL_IS_EMPTY  = 801, // 邮件附件已经领取
    MAIL_BAG_FULL  = 802, // 背包已满，不能领取附件
};

enum
{
    MONTH_CARD_EXPIRE   = 900,
    MONTH_CARD_REWARDED = 901,
};

enum
{
    WORLD_BOSS_IN_CD               = 1000,
    WORLD_BOSS_NON_NEED_REVIVE     = 1001,
    WORLD_BOSS_LESS_GOLD_REVIVE    = 1002,
    WORLD_BOSS_ENCOURAGE           = 1003,
    WORLD_BOSS_LESS_MONEY_ENCOURAGE = 1004,
    WORLD_BOSS_LESS_GOLD_ENCOURAGE  = 1005,
};

enum
{
	MART_ITEM_NOT_EXIST			= 1100,	// 非法道具
	MART_ITEM_OVERDUE			= 1101,	// 道具已经下架
	MART_ITEM_MAX_TIMES			= 1102,	// 已经达到个人购买的上限
	MART_ITEM_MAX_TOTAL_TIMES	= 1103,	// 道具已经售罄
	MART_ITEM_NEED_MONEY		= 1110,	// 铜钱不足
	MART_ITEM_NEED_GOLD			= 1111,	// 元宝不足
};

enum
{
	MINE_INVALID				= 1200,	// 非法的矿
	MINE_SELF_OCCUPY_EXIST		= 1201,	// 你已经占领了1个矿，不能重复占领
	MINE_OTHER_OCCUPY_EXIST		= 1202,	// 该矿不为空，已经被人占领
	MINE_NEED_STAMINA			= 1203,	// 体力不够
	MINE_NEED_GOLD				= 1204,	// 元宝不够
	MINE_NO_OCCUPY				= 1205,	// 矿没有被玩家占领，请直接占领该矿
	MINE_DUMP_OCCUPY			= 1206,	// 你已经占领了该矿，不能重复占领
	MINE_DELAY_SELF_ONLY		= 1207,	// 你只能延长自己占有矿的时间
	MINE_ABANDOM_SELF_ONLY		= 1208,	// 你只能取消自己占有矿
	MINE_FIND_NONE				= 1209,	// 找不到指定类型的空旷
};

enum
{
    LOGIN_SEVEN_BAG_FULL       = 1300, // 七日登录礼无法领取
};

enum
{
    CHAT_CONTENT_EMPTY    = 1400,
    CHAT_LOW_LEVEL        = 1401,
    CHAT_LESS_GOLD        = 1402,
};

enum
{
    CASH_LIMIT          = 1500, // 运镖人数太多
    CASH_NOT_EXIST      = 1501, // 没有类型的镖车
    CASH_NOT_ENOUGH_RES = 1502, // 花费不够
    CASH_START_LIMIT    = 1503, // 今天运镖次数已经达到上限
    CASH_ATTACK_LIMIT   = 1504, // 劫镖次数达到上限
    CASH_LOW_LEVEL      = 1505, // 等级不够
};
#endif
