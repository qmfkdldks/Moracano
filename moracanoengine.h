#ifndef MORACANOENGINE_H
#define MORACANOENGINE_H

#include "searchpart.h"
#include "sitepart.h"

class MoracanoEngine
{
public:
    MoracanoEngine();
    ~MoracanoEngine();

    void Search(QString & word);

private:
    SearchPart *mSearchPart;
    SitePart *mSitePart;
};

#endif // MORACANOENGINE_H
