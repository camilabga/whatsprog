/********************************************************************************
** Form generated from reading UI file 'newcircuito.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCIRCUITO_H
#define UI_NEWCIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewCircuito
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelNumIn;
    QSpinBox *spinNumIn;
    QLabel *labelNumOut;
    QSpinBox *spinNumOut;
    QLabel *labelNumPortas;
    QSpinBox *spinNumPortas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewCircuito)
    {
        if (NewCircuito->objectName().isEmpty())
            NewCircuito->setObjectName(QStringLiteral("NewCircuito"));
        NewCircuito->resize(207, 122);
        verticalLayout = new QVBoxLayout(NewCircuito);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelNumIn = new QLabel(NewCircuito);
        labelNumIn->setObjectName(QStringLiteral("labelNumIn"));

        gridLayout->addWidget(labelNumIn, 0, 0, 1, 1);

        spinNumIn = new QSpinBox(NewCircuito);
        spinNumIn->setObjectName(QStringLiteral("spinNumIn"));
        spinNumIn->setMinimum(1);

        gridLayout->addWidget(spinNumIn, 0, 1, 1, 1);

        labelNumOut = new QLabel(NewCircuito);
        labelNumOut->setObjectName(QStringLiteral("labelNumOut"));

        gridLayout->addWidget(labelNumOut, 1, 0, 1, 1);

        spinNumOut = new QSpinBox(NewCircuito);
        spinNumOut->setObjectName(QStringLiteral("spinNumOut"));
        spinNumOut->setMinimum(1);

        gridLayout->addWidget(spinNumOut, 1, 1, 1, 1);

        labelNumPortas = new QLabel(NewCircuito);
        labelNumPortas->setObjectName(QStringLiteral("labelNumPortas"));

        gridLayout->addWidget(labelNumPortas, 2, 0, 1, 1);

        spinNumPortas = new QSpinBox(NewCircuito);
        spinNumPortas->setObjectName(QStringLiteral("spinNumPortas"));
        spinNumPortas->setMinimum(1);

        gridLayout->addWidget(spinNumPortas, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(NewCircuito);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewCircuito);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewCircuito, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewCircuito, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewCircuito);
    } // setupUi

    void retranslateUi(QDialog *NewCircuito)
    {
        NewCircuito->setWindowTitle(QApplication::translate("NewCircuito", "Novo circuito", 0));
        labelNumIn->setText(QApplication::translate("NewCircuito", "N\303\272mero de entradas:", 0));
        labelNumOut->setText(QApplication::translate("NewCircuito", "N\303\272mero de sa\303\255das:", 0));
        labelNumPortas->setText(QApplication::translate("NewCircuito", "N\303\272mero de portas:", 0));
    } // retranslateUi

};

namespace Ui {
    class NewCircuito: public Ui_NewCircuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCIRCUITO_H
