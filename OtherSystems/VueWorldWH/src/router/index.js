import {createRouter, createWebHistory} from 'vue-router'
import index from "../views/UsrePage"
import world from "../views/ArticlePage/world"
import wenhzan from "../views/ArticlePage/wenzhan"
import RichTextEditor from "../views/ArticlePage/RichTextEditor"
import SingIn from "../views/UsrePage/singin"
import LogIn from "../views/UsrePage/login"
import movieIndex from "../views/demo1/MovieIndex"
import moviePlaying from "../views/demo1/MoviePlaying"
import moviePage from "../views/demo1/MoviePage"
import homePage from "../views/AbstractPage/HomePage"

import adminOfResources from "../views/AdminPage/AdminOfResources"
import adminOfArticle from "../views/AdminPage/AdminOfArticle"
import adminOfFile from "@/views/AdminPage/AdminOfFile";
import adminOfCensus from "@/views/AdminPage/AdminOfCensus";
import adminOfMysql from "@/views/AdminPage/AdminOfMysql"
import adminOfRedis from "@/views/AdminPage/AdminOfRedis"

const routerHistory = createWebHistory()
const router = createRouter({

    history: routerHistory,
    routes: [
        {path: '/', redirect: '/world'},
        {path: '/world', component: world},
        {path: '/index', component: index},
        {path: '/wenzhan', component: wenhzan},
        {path: '/text', component: RichTextEditor},
        {path: '/singin', component: SingIn},
        {path: '/login', component: LogIn},
        {path: '/movieIndex', component: movieIndex},
        {path: '/moviePlaying', component: moviePlaying},
        {path: '/moviePage', component: moviePage},
        {
            path: '/adminOfResources',
            component: adminOfResources,
            children: [
                {path: '/adminOfArticle', component: adminOfArticle,},
                {path: '/adminOfFile', component: adminOfFile,},
                {path: '/adminOfCensus', component: adminOfCensus},
                {path: '/adminOfMysql', component: adminOfMysql},
                {path: '/adminOfRedis', component: adminOfRedis}
            ]
        },
        {
            path: '/homepage',
            component: homePage,
            children: {
                path: '/',
            }
        }
    ]
})

export default router