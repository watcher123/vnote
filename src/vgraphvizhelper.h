#ifndef VGRAPHVIZHELPER_H
#define VGRAPHVIZHELPER_H

#include <QObject>

#include <QStringList>
#include <QProcess>

#include "vconstants.h"

class VGraphvizHelper : public QObject
{
    Q_OBJECT
public:
    explicit VGraphvizHelper(QObject *p_parent = nullptr);

    void processAsync(int p_id, TimeStamp p_timeStamp, const QString &p_format, const QString &p_text);

    void prepareCommand(QString &p_cmd, QStringList &p_args) const;

    static bool testGraphviz(const QString &p_dot, QString &p_msg);

signals:
    void resultReady(int p_id, TimeStamp p_timeStamp, const QString &p_format, const QString &p_result);

private slots:
    void handleProcessFinished(int p_exitCode, QProcess::ExitStatus p_exitStatus);

private:
    QString m_program;
    QStringList m_args;
};

#endif // VGRAPHVIZHELPER_H
