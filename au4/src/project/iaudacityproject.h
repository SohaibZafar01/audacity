#ifndef AU_PROJECT_IAUDACITYPROJECT_H
#define AU_PROJECT_IAUDACITYPROJECT_H

#include <memory>

#include "global/types/string.h"
#include "global/io/path.h"
#include "global/types/retval.h"
#include "global/async/notification.h"
#include "processing/dom/processingproject.h"

namespace au::project {
class IAudacityProject
{
public:
    virtual ~IAudacityProject() = default;

    virtual muse::Ret load(const muse::io::path_t& path, bool forceMode = false, const std::string& format = "") = 0;
    virtual void close() = 0;

    virtual muse::String title() const { return muse::String(); }
    virtual muse::io::path_t path() const = 0;
    virtual muse::async::Notification pathChanged() const = 0;
    virtual muse::ValNt<bool> needSave() const { return muse::ValNt<bool>(); }

    virtual muse::async::Notification displayNameChanged() const { return muse::async::Notification(); }
    virtual muse::async::Notification needSaveChanged() const { return muse::async::Notification(); }

    virtual const au::processing::ProcessingProjectPtr processingProject() const = 0;
};

using IAudacityProjectPtr = std::shared_ptr<IAudacityProject>;
}

#endif // AU_PROJECT_IAUDACITYPROJECT_H
