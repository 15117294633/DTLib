#ifndef BUILD_PRODUCT_H
#define BUILD_PRODUCT_H
#include "DTString.h"
namespace DTLib
{
    class Computer
    {
    public:
        //设置操作
        void SetmCpu(String cpu) { m_strCpu = cpu;}
        void SetmMainboard(String mainboard) { m_strMainboard = mainboard; }
        void SetmRam(String ram) { m_strRam = ram; }
        void SetVideoCard(String videoCard) { m_strVideoCard = videoCard; }
        //get操作
        String GetCPU() { return m_strCpu; }
        String GetMainboard()  { return m_strMainboard; }
        String GetRam() { return m_strRam; }
        String GetVideoCard() { return m_strVideoCard; }

    private:
        String m_strCpu;  // CPU
        String m_strMainboard;  // 主板
        String m_strRam;  // 内存
        String m_strVideoCard;  // 显卡
    };
}
#endif // BUILD_PRODUCT_H
