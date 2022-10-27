import { createApp } from 'vue'
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css'
import router from './router'
import axios from 'axios';
import Editor from '@tinymce/tinymce-vue'//富文本编辑器2

import videoPlay from 'vue3-video-play' // 引入组件
import 'vue3-video-play/dist/style.css' // 引入css
// import VueECharts from 'vue-echarts'//统计图

axios.defaults.withCredentials = true;//允许携带cookie解决无法获得session中的值问题

import App from './App.vue'

const app = createApp(App,{
    data: function () {
        return {
            wenhao: 'wenhaodaye'
        }
    },
})
// app.component('v-chart', VueECharts)//统计图
// app.use(VueECharts)//统计图
app.use(ElementPlus)
app.use(router)
app.use(videoPlay)
app.use(Editor)//富文本编辑器2
app.mount('#app')



