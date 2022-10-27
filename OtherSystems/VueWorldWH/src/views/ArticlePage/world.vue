<template>

  <div>
    <el-container>
      <!--    头部-->
      <el-header></el-header>

      <!--体部-->
      <el-main>
        <!--主体表格-->
        <el-container style="width: 1500px;">
          <el-aside style="width: 150px;">
          </el-aside>

          <el-main style="width:700px;">
            <ul>
              <el-input v-model="SearchBox" style="max-width: 360px">搜索文章</el-input>
              <el-button>搜索</el-button>
            </ul>
            <ul v-for="(item, key) in wenben" :key="key">

              <el-card class="box-card" shadow="hover"
                       body-style="text-align:left;width: 100%;padding: 10">
                <template #header>
                  <span v-on:click="goToArticle(item.id)">{{ item.title }}</span>
                  <span style="float: right;">{{ '作者:' + item.username }}</span>
                </template>
                <el-row :gutter="250">
                  <el-col :span="5">
                    <img src="../../assets/tu1.png" style="width: 230px; height: 140px" fit="cover">
                  </el-col>
                  <el-col :span="17">
                    <el-row>
                      <el-col v-on:click="goToArticle(item.id)">
                        {{ item.synopsis }}
                      </el-col>
                      <el-col>
                        <el-divider content-position="left">
                          点赞:{{ item.likeNumber }} 收藏:{{ item.favoritesNumber }} 留言:{{ item.commentsNumber }}
                        </el-divider>
                      </el-col>
                      <el-col>
                        发布时间:{{ item.issuingTime }}
                      </el-col>
                    </el-row>
                  </el-col>
                </el-row>
              </el-card>

            </ul>
            <ul>
              <el-pagination
                  id="yema" background layout="prev, pager, next"
                  :total="total"
                  v-model:current-page="CurrentPage"
                  :pager-count="PagerCount"
                  :page-size="PageSize"/>
              当前处于第{{ CurrentPage }}页,共有{{ total }}条数据。
            </ul>
          </el-main>

          <el-aside style="width: 400px;">
          </el-aside>

        </el-container>


      </el-main>
      <el-divider></el-divider>

      <!--尾部-->
      <el-footer></el-footer>
    </el-container>

  </div>
</template>


<script type="text/javascript">
import axios from "axios";
import {getArticleList} from "@/api";

export default {
  name: "WorldH",
  data() {
    return {
      SearchBox: '',//搜索框内容
      //文章数据总条数
      total: 2000,
      //文章当前页码
      CurrentPage: 1,
      //页码数量
      PagerCount: 13,
      //每页显示文章数据条数
      PageSize: 10,

      activeIndex: '1',
      activeIndex2: '1',
      wenben: [
        {
          title: '',//文章标题
          //大概内容
          synopsis: "春，送别了冷冷的冬寒，飘过季节轮回的光阴古道。用一身明媚的阳光，温润着大地的胸怀。将山川冰封着的心复苏，把小草从冬眠的梦中唤醒，让飘飞的柳絮化作了点点岁月的流光，更在清风舞柳的暖阳中寻找着时光的明媚。",
          username: "wenhao",//作者昵称
          issuingTime: new Date(),//文章发表时间
          id: "1",//文章id
          likeNumber: '65412',//文章点赞数
          favoritesNumber: '4215',//文章收藏数
          commentsNumber: '7845442',//文章评论数
        },
      ],
      lists: [
        {img: require('../../assets/tu6.png')},
        {img: require('../../assets/tu6.png')},
        {img: require('../../assets/tu6.png')},
        {img: require('../../assets/tu6.png')},
        {img: require('../../assets/tu6.png')},
      ],
      PostsList: [
        {name: "历史上第一篇帖子", author: "第一位作者", content: "历史上第一篇帖子的大概内容。。。。"},
        {name: "历史上第二篇帖子", author: "第一位作者", content: "历史上第二篇帖子的大概内容。。。。"},
        {name: "历史上第三篇帖子", author: "第一位作者", content: "历史上第三篇帖子的大概内容。。。。"}
      ],

      currentDate: new Date()

    }
  },
  methods: {
    handleSelect(key, keyPath) {
      console.log(key, keyPath);
    },
    handleEdit(index, row) {
      console.log(index, row);
    },
    getArticleList: function () {
      getArticleList(this.CurrentPage).then(res => {
        this.wenben = JSON.parse(res.data);
      }).catch(err => alert(err));
    },
    huoqu: function () {
      alert("获取数据");
      axios.post("/user/he").then(res => {
        console.log(res);
        //将数据赋值到vue实例中的数据属性users；
        //不能使用this，在axios回调函数中表示窗口，不是vue实例
        alert(res.data);
        // app.lists = res.data;
      }).catch(err => alert(err));
    },
    goToArticle(value) {
      this.$router.push({path: "/wenzhan", query: {value}});
    },
  },
  created() {
    //this.setsize(2000);
    setTimeout("console.log('加载数据完成')", 3000 );
    this.getArticleList();

  },
  //监听器
  watch: {
    CurrentPage() {
      // 当CurrentPage数据发生变化以后执行方法
      alert("请求第" + this.CurrentPage + "页的数据");
    }
  }

}
</script>

<style>

.button {
  padding: 0;
  float: right;
}

.image {
  width: 100%;
  display: block;
}

.el-header, .el-footer {
  text-align: left;
  line-height: 20px;
  padding: 3px;
}

.el-aside {
  text-align: left;
  line-height: 20px;
  padding: 5px;
  margin: 0;
}

.el-main {
  text-align: left;
  line-height: 20px;
  padding: 5px;

}

.el-card {
  margin-left: -40px;;
}

</style>
