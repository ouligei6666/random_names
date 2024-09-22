#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QTime>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <qspinbox.h>

class RandomCallApp : public QWidget {
    Q_OBJECT

public:
    RandomCallApp(QWidget *parent = nullptr) : QWidget(parent) {
        // 初始化UI
        initUI();
        // 连接信号和槽
        connectSignalsAndSlots();
    }
    QStringList myList={"李博奥","王雨瞳","张明奥","赵泽","王紫涵","李慧茹","徐志刚","徐长渠","郭云梦","王京哲","杨子涵","王宇航","王顺航","奚子墨","刘子怡","姚佳彤","许国强","孟子寒","孔紫裙","邹永昊","李浩然","毕梦迪","周慧雅","苏本乾","王敏","姬翔","于昭杰","杨潭","李乐","苏明嘉","任术博","耿子轩","冯昌铭","徐素菲","郝子娴","李兆陶","王淼","刘欣雅","许浩然","曹琳琳","刘念贺","吴雨芯","杨国斌","张佳俊","孔舒","孔维乐","刘海迎","王梦琪","耿宇航","张俊博","王俊杰","陶颖","高佳乐","狄标","王涵","李沛","冯昌信","宋庆彤","李博涵","林淼然","高家兴","张梦缘"};

private:
    QPushButton *startButton;
    QLabel *nameLabel;
    QLabel *authorLabel;
    QSpinBox *myspinBox;
    QListWidget *nameList;


    void initUI() {
        // 设置窗口标题和大小
        setWindowTitle("4班随机点名器");
        setFixedSize(300, 400);

        // 创建UI组件
        startButton = new QPushButton("开始点名", this);
        nameLabel = new QLabel("准备点名...", this);
        authorLabel =new QLabel("@author is 泥跌 (๑¯ω¯๑)，赠送给老陈", this);
        myspinBox = new QSpinBox(this);
        nameList = new QListWidget(this);

        myspinBox->setValue(1);

        nameList->setStyleSheet("QListWidget { font-size: 20pt; }");

        // 添加一些示例姓名
        nameList->addItems({"开始点名"});

        // 布局
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(nameList);
        layout->addWidget(myspinBox);
        layout->addWidget(startButton);
        layout->addWidget(nameLabel);
        layout->addWidget(authorLabel);
    }

    void connectSignalsAndSlots() {
        // 连接按钮点击信号和槽函数
        connect(startButton, &QPushButton::clicked, this, &RandomCallApp::startCall);
    }

public slots:
    void startCall() {
        // 获取列表中的姓名数量
        int count = myList.size();
        if (count == 0) {
            QMessageBox::warning(this, "警告", "姓名列表为空！");
            return;
        }
        //标记数组，看是否随机过
        int flag[100]={0};

        //清空列表
        nameList->clear();

        // 获取需要随机的数量
        int randnum=myspinBox->value();
        int i=0;
        if(randnum<count){
            while(i<randnum){
                QTime time = QTime::currentTime();
                srand(time.msec() + time.second() * 1000);
                int randomIndex = rand() % count;
                if(flag[randomIndex]==0){
                    nameList->addItem(myList[randomIndex]);
                    flag[randomIndex]=1;
                    i++;
                }

            }
            nameLabel->setText("点名完成");
        }else{
            nameLabel->setText("随机个数大于学生总数");
        }



    }
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RandomCallApp randomCallApp;
    randomCallApp.show();
    return app.exec();
}
