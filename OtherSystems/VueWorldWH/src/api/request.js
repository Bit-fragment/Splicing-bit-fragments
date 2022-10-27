import axios from "axios";

axios.defaults.baseURL = 'http://127.0.0.1:8080';

const request = axios.create({
    //超时时间
    timeout: 1000,
    // transformRequest: [function (data, headers) {
    //     // 对发送的 data 进行任意转换处理

    //     return data;
    // }],
    // `transformResponse` 在传递给 then/catch 前，允许修改响应数据
    transformResponse: [function (data) {
        // 对接收的 data 进行任意转换处理
        // console.log(`对接收的 data 进行任意转换处理${data}`)
        // alert("transformResponse: "+data)
        return data
    }],
    // 自定义请求头
    // headers: { 'X-Requested-With': 'XMLHttpRequest' },
    // `params` 是与请求一起发送的 URL 参数
    // 必须是一个简单对象或 URLSearchParams 对象
    // params: {
    //     ID: 12345
    // },
    // `withCredentials` 表示跨域请求时是否需要使用凭证
    withCredentials: true,
    // `responseType` 表示浏览器将要响应的数据类型
    // 选项包括: 'arraybuffer', 'document', 'json', 'text', 'stream'
    // 浏览器专属：'blob'
    responseType: 'json', // 默认值

    // `responseEncoding` 表示用于解码响应的编码 (Node.js 专属)
    // 注意：忽略 `responseType` 的值为 'stream'，或者是客户端请求
    // Note: Ignored for `responseType` of 'stream' or client-side requests
    responseEncoding: 'utf8', // 默认值

    // `onUploadProgress` 允许为上传处理进度事件
    // 浏览器专属
    // onUploadProgress: function (progressEvent) {
    //     // 处理原生进度事件
    // },

    // `onDownloadProgress` 允许为下载处理进度事件
    // 浏览器专属
    // onDownloadProgress: function (progressEvent) {
    //     // 处理原生进度事件
    // },
    // `validateStatus` 定义了对于给定的 HTTP状态码是 resolve 还是 reject promise。
    // 如果 `validateStatus` 返回 `true` (或者设置为 `null` 或 `undefined`)，
    // 则promise 将会 resolved，否则是 rejected。
    validateStatus: function (status) {
        return status >= 200 && status < 300; // 默认值
    },
    // `proxy` 定义了代理服务器的主机名，端口和协议。
    // 您可以使用常规的`http_proxy` 和 `https_proxy` 环境变量。
    // 使用 `false` 可以禁用代理功能，同时环境变量也会被忽略。
    // `auth`表示应使用HTTP Basic auth连接到代理，并且提供凭据。
    // 这将设置一个 `Proxy-Authorization` 请求头，它会覆盖 `headers` 中已存在的自定义 `Proxy-Authorization` 请求头。
    // 如果代理服务器使用 HTTPS，则必须设置 protocol 为`https`
    // proxy: {
    //     protocol: 'https',
    //     host: '127.0.0.1',
    //     port: 9000,
    //     auth: {
    //         username: 'mikeymike',
    //         password: 'rapunz3l'
    //     }
    // },
});

// 添加请求拦截器
//config配置对象
// axios.interceptors.request.use(function (config) {
//     // 在发送请求之前做些什么
//     return config;
//   }, function (error) {
//     // 对请求错误做些什么
//     return Promise.reject(error);
// });


// 添加响应拦截器
//response响应结果
request.interceptors.response.use(function (response) {
    // 2xx 范围内的状态码都会触发该函数。
    // 对响应数据做点什么
    // console.log(request)
    return response
}, function (error) {
    // 超出 2xx 范围的状态码都会触发该函数。
    // 对响应错误做点什么
    return Promise.reject(error)
});


export {request}