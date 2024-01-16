/********************************************************************************
** Form generated from reading UI file 'chesseditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSEDITDIALOG_H
#define UI_CHESSEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChessEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChessEditDialog)
    {
        if (ChessEditDialog->objectName().isEmpty())
            ChessEditDialog->setObjectName(QString::fromUtf8("ChessEditDialog"));
        ChessEditDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ChessEditDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(ChessEditDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(ChessEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ChessEditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ChessEditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ChessEditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ChessEditDialog);
    } // setupUi

    void retranslateUi(QDialog *ChessEditDialog)
    {
        ChessEditDialog->setWindowTitle(QCoreApplication::translate("ChessEditDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessEditDialog: public Ui_ChessEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSEDITDIALOG_H
