/********************************************************************************
** Form generated from reading UI file 'modificarporta.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARPORTA_H
#define UI_MODIFICARPORTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModificarPorta
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelPorta;
    QLabel *labelIdPorta;
    QLabel *labelTipoPorta;
    QComboBox *comboTipoPorta;
    QLabel *labelNumInputs;
    QSpinBox *spinNumInputs;
    QLabel *labelInput1;
    QSpinBox *spinInput1;
    QLabel *labelInput2;
    QSpinBox *spinInput2;
    QLabel *labelInput3;
    QSpinBox *spinInput3;
    QLabel *labelInput4;
    QSpinBox *spinInput4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ModificarPorta)
    {
        if (ModificarPorta->objectName().isEmpty())
            ModificarPorta->setObjectName(QStringLiteral("ModificarPorta"));
        ModificarPorta->resize(174, 225);
        verticalLayout = new QVBoxLayout(ModificarPorta);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelPorta = new QLabel(ModificarPorta);
        labelPorta->setObjectName(QStringLiteral("labelPorta"));

        gridLayout->addWidget(labelPorta, 0, 0, 1, 1);

        labelIdPorta = new QLabel(ModificarPorta);
        labelIdPorta->setObjectName(QStringLiteral("labelIdPorta"));

        gridLayout->addWidget(labelIdPorta, 0, 1, 1, 1);

        labelTipoPorta = new QLabel(ModificarPorta);
        labelTipoPorta->setObjectName(QStringLiteral("labelTipoPorta"));

        gridLayout->addWidget(labelTipoPorta, 1, 0, 1, 1);

        comboTipoPorta = new QComboBox(ModificarPorta);
        comboTipoPorta->setObjectName(QStringLiteral("comboTipoPorta"));

        gridLayout->addWidget(comboTipoPorta, 1, 1, 1, 1);

        labelNumInputs = new QLabel(ModificarPorta);
        labelNumInputs->setObjectName(QStringLiteral("labelNumInputs"));

        gridLayout->addWidget(labelNumInputs, 2, 0, 1, 1);

        spinNumInputs = new QSpinBox(ModificarPorta);
        spinNumInputs->setObjectName(QStringLiteral("spinNumInputs"));
        spinNumInputs->setMinimum(1);
        spinNumInputs->setMaximum(4);

        gridLayout->addWidget(spinNumInputs, 2, 1, 1, 1);

        labelInput1 = new QLabel(ModificarPorta);
        labelInput1->setObjectName(QStringLiteral("labelInput1"));

        gridLayout->addWidget(labelInput1, 3, 0, 1, 1);

        spinInput1 = new QSpinBox(ModificarPorta);
        spinInput1->setObjectName(QStringLiteral("spinInput1"));

        gridLayout->addWidget(spinInput1, 3, 1, 1, 1);

        labelInput2 = new QLabel(ModificarPorta);
        labelInput2->setObjectName(QStringLiteral("labelInput2"));

        gridLayout->addWidget(labelInput2, 4, 0, 1, 1);

        spinInput2 = new QSpinBox(ModificarPorta);
        spinInput2->setObjectName(QStringLiteral("spinInput2"));

        gridLayout->addWidget(spinInput2, 4, 1, 1, 1);

        labelInput3 = new QLabel(ModificarPorta);
        labelInput3->setObjectName(QStringLiteral("labelInput3"));

        gridLayout->addWidget(labelInput3, 5, 0, 1, 1);

        spinInput3 = new QSpinBox(ModificarPorta);
        spinInput3->setObjectName(QStringLiteral("spinInput3"));

        gridLayout->addWidget(spinInput3, 5, 1, 1, 1);

        labelInput4 = new QLabel(ModificarPorta);
        labelInput4->setObjectName(QStringLiteral("labelInput4"));

        gridLayout->addWidget(labelInput4, 6, 0, 1, 1);

        spinInput4 = new QSpinBox(ModificarPorta);
        spinInput4->setObjectName(QStringLiteral("spinInput4"));

        gridLayout->addWidget(spinInput4, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(ModificarPorta);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ModificarPorta);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModificarPorta, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModificarPorta, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModificarPorta);
    } // setupUi

    void retranslateUi(QDialog *ModificarPorta)
    {
        ModificarPorta->setWindowTitle(QApplication::translate("ModificarPorta", "Dialog", 0));
        labelPorta->setText(QApplication::translate("ModificarPorta", "PORTA:", 0));
        labelIdPorta->setText(QString());
        labelTipoPorta->setText(QApplication::translate("ModificarPorta", "Tipo da porta:", 0));
        labelNumInputs->setText(QApplication::translate("ModificarPorta", "N\302\272 de entradas:", 0));
        labelInput1->setText(QApplication::translate("ModificarPorta", "Id da entrada 1:", 0));
        labelInput2->setText(QApplication::translate("ModificarPorta", "Id da entrada 2:", 0));
        labelInput3->setText(QApplication::translate("ModificarPorta", "Id da entrada 3:", 0));
        labelInput4->setText(QApplication::translate("ModificarPorta", "Id da entrada 4:", 0));
    } // retranslateUi

};

namespace Ui {
    class ModificarPorta: public Ui_ModificarPorta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARPORTA_H
