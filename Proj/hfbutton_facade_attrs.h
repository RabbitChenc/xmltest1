#ifndef HFBUTTON_FACADE_ATTRS_H
#define HFBUTTON_FACADE_ATTRS_H

#include <QXmlStreamReader>

QT_BEGIN_NAMESPACE
    class QString;
    class QXmlStreamReader;
    class QXmlStreamAttributes;
QT_END_NAMESPACE


typedef struct {
    int m_leftMargin;
    int m_topMargin;
    int m_rightMargin;
    int m_bottomMargin;
    int m_backgroundColor;
    int m_textColor;
    QString m_imgFilename;
} tHFButtonFacadeState;

class HFButtonFacadeAttrs
{
public:
    HFButtonFacadeAttrs();
    virtual ~HFButtonFacadeAttrs();


    const tHFButtonFacadeState * GetNormalAttrs();
    const tHFButtonFacadeState * GetPressedAttrs();
    const tHFButtonFacadeState * GetDisabledAttrs();

    void SetAttrs(tHFButtonFacadeState& state);
    void debugTest(tHFButtonFacadeState& state);

protected:
    tHFButtonFacadeState stateNormal;
    tHFButtonFacadeState statePressd;
    tHFButtonFacadeState stateDisabled;

private:
    QXmlStreamReader m_xmlReader;
    QXmlStreamAttributes attributes;
};

#endif
