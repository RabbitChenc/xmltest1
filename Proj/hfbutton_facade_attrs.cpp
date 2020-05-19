#include "./Proj/hfbutton_facade_attrs.h"
#include <QXmlStreamReader>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QDomDocument>
#include <QXmlStreamAttributes>


HFButtonFacadeAttrs::HFButtonFacadeAttrs()
{

    //打开文件
    QFile qtFile("/home/rabbitchenc/Qt/btn_class6/f.xml");

    if(!qtFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         qDebug()<< "Open failed." << endl;
         return;
    }

     //读取并解析xml文件
     m_xmlReader.setDevice(&qtFile);
     //如果没有读到结尾
     while(!m_xmlReader.atEnd()){

         QXmlStreamReader::TokenType token = m_xmlReader.readNext();

         if(token == QXmlStreamReader::StartElement){
             qDebug() <<m_xmlReader.name()<<endl;
             attributes = m_xmlReader.attributes();

             if(m_xmlReader.name() == "Normal"){
                 GetNormalAttrs();
             }
             if(m_xmlReader.name() == "Press"){
                 GetPressedAttrs();
             }
             if(m_xmlReader.name() == "Disabled"){
                 GetDisabledAttrs();
             }
         }
     }
     if(m_xmlReader.hasError()){
        qDebug() << "error in file " <<endl;
     }
    qtFile.close();
}
//获取按键正常状态的属性
const tHFButtonFacadeState* HFButtonFacadeAttrs::GetNormalAttrs()
{
    SetAttrs(stateNormal);
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetPressedAttrs()
{
   SetAttrs(statePressd);
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetDisabledAttrs()
{
     SetAttrs(stateDisabled);
}


void HFButtonFacadeAttrs::SetAttrs(tHFButtonFacadeState &state)
{
    bool ok0;
    if(attributes.hasAttribute("background")){
        QString backcolor = attributes.value("background").toString() ;
        state.m_backgroundColor = backcolor.toInt(&ok0,16);
    }
    if(attributes.hasAttribute("left")){
        QString left = attributes.value("left").toString();
        state.m_leftMargin = left.toInt(&ok0,16);
    }
    if(attributes.hasAttribute("top")){
        QString top = attributes.value("top").toString();
        state.m_topMargin = top.toInt(&ok0,16);
    }
    if(attributes.hasAttribute("right")){
        QString right = attributes.value("right").toString();
        state.m_rightMargin = right.toInt(&ok0,16);
    }
    if(attributes.hasAttribute("bottom")){
        QString bottom = attributes.value("bottom").toString();
        state.m_bottomMargin = bottom.toInt(&ok0,16);
    }
    if(attributes.hasAttribute("text_color")){
        QString text_color = attributes.value("text_color").toString();
        state.m_textColor = text_color.toInt(&ok0,16);
    }
        state.m_imgFilename = m_xmlReader.readElementText();

        debugTest(state);
}


void HFButtonFacadeAttrs::debugTest(tHFButtonFacadeState &state)
{
    qDebug() << state.m_textColor << ";" << state.m_topMargin << ";" << state.m_leftMargin <<";"
             <<state.m_imgFilename <<";" << state.m_rightMargin <<";" << state.m_bottomMargin << ";"
             <<state.m_backgroundColor <<endl;
}




HFButtonFacadeAttrs::~HFButtonFacadeAttrs()
{

}
