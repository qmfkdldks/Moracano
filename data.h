#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QVariant>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = 0);
    virtual void setData(QVariantList &inVector) = 0;
    virtual QVariantList getData() = 0;

signals:

public slots:

private:

};

#endif // DATA_H
