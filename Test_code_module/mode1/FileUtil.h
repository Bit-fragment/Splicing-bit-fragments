//
// Created by XMZR on 2022/7/18.
//

#ifndef MYCPPWORLD_FILEUTIL_H
#define MYCPPWORLD_FILEUTIL_H

class FileUtil {
public:
    FileUtil();

    ~FileUtil();

    std::vector<std::string> readFileBody(const std::string &url);

    bool addFileBody(const std::string &url, const std::string &body);

};


#endif //MYCPPWORLD_FILEUTIL_H
