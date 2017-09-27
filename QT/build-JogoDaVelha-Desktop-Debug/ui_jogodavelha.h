/********************************************************************************
** Form generated from reading UI file 'jogodavelha.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOGODAVELHA_H
#define UI_JOGODAVELHA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JogoDaVelha
{
public:
    QAction *actionNovo_Jogo;
    QAction *actionSair;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tabuleiro;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelVez;
    QLabel *imagemVez;
    QLabel *labelVencedor;
    QLabel *imagem_vencedor;
    QMenuBar *menuBar;
    QMenu *menuJogo;
    QMenu *menuSobre;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JogoDaVelha)
    {
        if (JogoDaVelha->objectName().isEmpty())
            JogoDaVelha->setObjectName(QStringLiteral("JogoDaVelha"));
        JogoDaVelha->resize(400, 300);
        JogoDaVelha->setIconSize(QSize(40, 40));
        actionNovo_Jogo = new QAction(JogoDaVelha);
        actionNovo_Jogo->setObjectName(QStringLiteral("actionNovo_Jogo"));
        actionSair = new QAction(JogoDaVelha);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        centralWidget = new QWidget(JogoDaVelha);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabuleiro = new QTableWidget(centralWidget);
        if (tabuleiro->columnCount() < 3)
            tabuleiro->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabuleiro->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabuleiro->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabuleiro->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tabuleiro->rowCount() < 3)
            tabuleiro->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabuleiro->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabuleiro->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabuleiro->setVerticalHeaderItem(2, __qtablewidgetitem5);
        tabuleiro->setObjectName(QStringLiteral("tabuleiro"));
        tabuleiro->setMaximumSize(QSize(182, 182));
        tabuleiro->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabuleiro->setSelectionMode(QAbstractItemView::SingleSelection);
        tabuleiro->horizontalHeader()->setVisible(false);
        tabuleiro->horizontalHeader()->setDefaultSectionSize(60);
        tabuleiro->horizontalHeader()->setHighlightSections(false);
        tabuleiro->horizontalHeader()->setMinimumSectionSize(60);
        tabuleiro->verticalHeader()->setVisible(false);
        tabuleiro->verticalHeader()->setDefaultSectionSize(60);
        tabuleiro->verticalHeader()->setHighlightSections(false);
        tabuleiro->verticalHeader()->setMinimumSectionSize(60);

        horizontalLayout->addWidget(tabuleiro);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelVez = new QLabel(centralWidget);
        labelVez->setObjectName(QStringLiteral("labelVez"));
        labelVez->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(labelVez);

        imagemVez = new QLabel(centralWidget);
        imagemVez->setObjectName(QStringLiteral("imagemVez"));
        imagemVez->setMaximumSize(QSize(60, 60));
        imagemVez->setFrameShape(QFrame::Box);
        imagemVez->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imagemVez);

        labelVencedor = new QLabel(centralWidget);
        labelVencedor->setObjectName(QStringLiteral("labelVencedor"));
        labelVencedor->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(labelVencedor);

        imagem_vencedor = new QLabel(centralWidget);
        imagem_vencedor->setObjectName(QStringLiteral("imagem_vencedor"));
        imagem_vencedor->setMaximumSize(QSize(60, 60));
        imagem_vencedor->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(imagem_vencedor);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        JogoDaVelha->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(JogoDaVelha);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuJogo = new QMenu(menuBar);
        menuJogo->setObjectName(QStringLiteral("menuJogo"));
        menuSobre = new QMenu(menuBar);
        menuSobre->setObjectName(QStringLiteral("menuSobre"));
        JogoDaVelha->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JogoDaVelha);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JogoDaVelha->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(JogoDaVelha);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JogoDaVelha->setStatusBar(statusBar);

        menuBar->addAction(menuJogo->menuAction());
        menuBar->addAction(menuSobre->menuAction());
        menuJogo->addAction(actionNovo_Jogo);
        menuJogo->addAction(actionSair);

        retranslateUi(JogoDaVelha);

        QMetaObject::connectSlotsByName(JogoDaVelha);
    } // setupUi

    void retranslateUi(QMainWindow *JogoDaVelha)
    {
        JogoDaVelha->setWindowTitle(QApplication::translate("JogoDaVelha", "JogoDaVelha", 0));
        actionNovo_Jogo->setText(QApplication::translate("JogoDaVelha", "Novo Jogo", 0));
        actionSair->setText(QApplication::translate("JogoDaVelha", "Sair", 0));
        labelVez->setText(QApplication::translate("JogoDaVelha", "Jogador da Vez", 0));
        imagemVez->setText(QString());
        labelVencedor->setText(QApplication::translate("JogoDaVelha", "Vencedor", 0));
        imagem_vencedor->setText(QString());
        menuJogo->setTitle(QApplication::translate("JogoDaVelha", "Jogo", 0));
        menuSobre->setTitle(QApplication::translate("JogoDaVelha", "Sobre", 0));
    } // retranslateUi

};

namespace Ui {
    class JogoDaVelha: public Ui_JogoDaVelha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOGODAVELHA_H
