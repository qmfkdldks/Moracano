#include "moracanoengine.h"

MoracanoEngine::MoracanoEngine()
{
    mSearchPart = new SearchPart;
    mSitePart = new SitePart;
}

MoracanoEngine::~MoracanoEngine()
{
    delete mSearchPart;
    delete mSitePart;
}

void MoracanoEngine::Search(QString &word)
{
    mSearchPart->Search(word);
}
