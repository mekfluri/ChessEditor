/********************************************************************************
** Form generated from reading UI file 'chesssquaredialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSSQUAREDIALOG_H
#define UI_CHESSSQUAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessSquareDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ChessSquareDialog)
    {
        if (ChessSquareDialog->objectName().isEmpty())
            ChessSquareDialog->setObjectName(QString::fromUtf8("ChessSquareDialog"));
        ChessSquareDialog->resize(410, 313);
        buttonBox = new QDialogButtonBox(ChessSquareDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(ChessSquareDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 10, 181, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        label = new QLabel(ChessSquareDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 41, 21));
        label_2 = new QLabel(ChessSquareDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 150, 41, 31));

        retranslateUi(ChessSquareDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ChessSquareDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ChessSquareDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ChessSquareDialog);
    } // setupUi

    void retranslateUi(QDialog *ChessSquareDialog)
    {
        ChessSquareDialog->setWindowTitle(QCoreApplication::translate("ChessSquareDialog", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("ChessSquareDialog", "Empty", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("ChessSquareDialog", "Black", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ChessSquareDialog", "White", nullptr));

        comboBox->setCurrentText(QString());
        comboBox_2->setItemText(0, QString());
        comboBox_2->setItemText(1, QCoreApplication::translate("ChessSquareDialog", "King", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("ChessSquareDialog", "Queen", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("ChessSquareDialog", "Rook", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("ChessSquareDialog", "Bishop", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("ChessSquareDialog", "Knight", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("ChessSquareDialog", "Pawn", nullptr));

        label->setText(QCoreApplication::translate("ChessSquareDialog", "Color", nullptr));
        label_2->setText(QCoreApplication::translate("ChessSquareDialog", "Type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessSquareDialog: public Ui_ChessSquareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSSQUAREDIALOG_H
