import {request} from "./request"

/**
 * 将所有请求统一放置到此处进行管理，api前缀已配置完成
 */

/**
 * 获取建议列表
 * /api/suggest   get
 */
//  export const getSuggest = (input) => {
//     return request.get(`/suggest`,{
//         params:{
//             input
//         }
//     })
// }
const LoginStatus = false; //打算设置一个全局变量 以方便判断用户是否登录 以此为准管理一些主键
export {LoginStatus}
export const updateLoginStatus = (value) => {
    // eslint-disable-next-line no-const-assign
    LoginStatus = value;
}

/*
* 测试1
* */
export const test1 = (input) => {
    return request.get(`/test2`, {
        params: {input}
    });
}

//登录方法
export const singin = (input) => {
    //{}表示的是對象裝了什麼 {input}表示的的是一個對象里有 input 和 單獨 input 表示的意義不一樣
    return request.post(`/user/singinuser`, input
    );

}

//直接登录方法
export const singinx = (input) => {
    return request.post(`/user/singinuserx`, input
    );

}

//退出登录
export const signout = (input) => {
    return request.post("/user/singout", input);
}

//获取数据(富文本)
export const huoqu = (input) => {
    return request.post("/article/getArticle", input);
}

//提交数据(富文本)
export const tijiao = (data) => {
    return request.post("/admin/article/addArticle", data);
}

//获取数据(用户数据index.vue)
export const huoqu1 = (input) => {
    return request.post("/user/he", input);
}

//获取评论
export const getReviews = (ArticleId, CurrentPage) => {
    return request.post("/article/getReviews", {
        CurrentPage: CurrentPage,
        ArticleId: ArticleId,
    });
}

//获取文章集合
export const getArticleList = (value) => {
    return request.post("/article/getArticleList", {
        CurrentPage: value,
    });
}

//发表文章
export const PublishArticle = (value) => {
    return request.post(
        "/admin/article/publishArticle",
        {
            value: value,
        }
    )
}

export const SubmitArticleComments = (value) => {
    return request.post(
        "/comment/addComment", value
    )
}
//文件下载
// export const fileDownload = (fileName) => {
//     return request.post(
//         "/file/fileDownload",
//         {
//             fileName: fileName,
//         }
//     )
// }

//获取要下载的文件列表
export const getFileNameList = () => {
    return request.post(
        "/file/getFileNameList"
    )
}

//获取用户登录状态
export const getLoginStatus = () => {
    return request.post(
        "/user/getLoginStatus"
    )
}

//获取图片url
export const getImgFileUrlList = () =>{
    return request.post(
        "/admin/resour/getImgFileUrlList"
    )
}

// ==========Redis=============
export const addRedisData = (key,value) => {
    return request.post("/serverdata/addRedisData", {
        body: {key,value},
    });
}
export const remRedisData = (key) => {
    return request.post(`/serverdata/remRedisData`, {
        body: {key}
    });
}
export const setRedisData = (key,value) => {
    return request.post(`/serverdata/setRedisData`, {
        body: {key,value}
    });
}
export const getRedisData = (key) => {
    return request.post(`/serverdata/getRedisData`, {
        body: {key}
    });
}
export const getRedisDataAll = () => {
    return request.post(`/serverdata/getRedisDataAll`, {

    });
}
