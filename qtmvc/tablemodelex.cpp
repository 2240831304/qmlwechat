
#include "tablemodelex.h"

modelex::modelex(QObject *parent):
    QAbstractTableModel(parent)
{
    //创建映射
    armyMap[1]=tr("空军");
    armyMap[2]=tr("海军");
    armyMap[3]=tr("陆军");
    armyMap[4]=tr("海军陆战队");

    weaponTypeMap[1]=tr("轰炸机");
    weaponTypeMap[2]=tr("战斗机");
    weaponTypeMap[3]=tr("航空母舰");
    weaponTypeMap[4]=tr("驱逐舰");
    weaponTypeMap[5]=tr("直升机");
    weaponTypeMap[6]=tr("坦克");
    weaponTypeMap[7]=tr("两栖攻击舰");
    weaponTypeMap[8]=tr("两栖战车");

    //绘制模型
    populateModel();
}



//获取模型的行数
int modelex::rowCount(const QModelIndex &parent) const
{
    return army.size();
}

//返回模型的列数
int modelex::columnCount(const QModelIndex &parent) const
{
    return 4;
}

//返回指定索引的数据,即将数值映射为文字
//循环把模型的每行每列给绘制了(函数名不能换成其他名字)
QVariant modelex::data(const QModelIndex &index, int role) const
{
#if 1
    if(!index.isValid())
    {
        return QVariant();
    }

    //模型中的条目可以有不同个角色,这样就可以在不同的情况下提供不同的数据.
    //如,Qt::DisplayRole用来存取视图中显示的文字,角色由枚举类Qt::ItemDataRole定义
    //Qt::DisplayRole   显示文字
    //Qt::DecorationRole   绘制装饰数据(通常是图标)
    //Qt::EditRole   在编辑器中编辑的数据
    //Qt::ToolTipRole   工具提示
    //Qt::StatusTipRole   状态栏提示
    //Qt::WhatsThisRole   What's This文字
    //Qt::SizeHintRole   尺寸提示
    //Qt::FontRole   默认代理的绘制使用的字体
    //Qt::TextAlignmentRole   默认代理的对齐方式
    //Qt::BackgroundRole   默认代理的背景画刷
    //Qt::ForegroundRole   默认代理的前景画刷
    //Qt::CheckStateRole   默认代理的检查框状态
    //Qt::UserRole   用户自定义的数据的起始位置
    if(role==Qt::DisplayRole)
    {
        //遍历没一列
        switch(index.column())
        {
        case 0:
            //当前行数对应的军队
            return armyMap[army[index.row()]];
            break;
        case 1:
            //当前行数对应的类型,以及此类型对应的武器种类
            return weaponTypeMap[weaponType[index.row()]];
        case 2:
            //当前行数对应的武器
            return weapon[  index.row()  ];
        default:
            return QVariant();
        }
    }
#endif
    return QVariant();
}

//返回固定的表头数据,设置水平表头的标题(内部循环实现)
QVariant modelex::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole&&orientation==Qt::Horizontal)
        return header[section];

    return QAbstractTableModel::headerData(section,orientation,role);
}

//绘制
void modelex::populateModel()
{
    //表头
    header<<tr("军种")<<tr("武器种类")<<tr("武器")<<tr("测试");
    //军队
    army<<1<<2<<3<<4<<2<<4<<3<<1;
    //武器种类
    weaponType<<1<<3<<5<<7<<4<<8<<6<<3;
    //武器
    weapon<<tr("B-2")<<tr("尼米兹级")<<tr("黄蜂级")<<tr("阿利伯克级")
         <<tr("阿帕奇")<<tr("AAAV")<<tr("M1A1")<<tr("F-22");
}
