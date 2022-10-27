<template>
<h2>抽象数据页面</h2>

  <el-container style="width: 1500px;">
    <el-aside style="width: 350px;">

    </el-aside>

    <el-main style="width:700px;">
      <ul v-for="(Posts, keey) in wenben" :key="keey">
        <el-card class="box-card" shadow="hover" body-style="text-align:left;width: 100%;padding: 10">
          <template #header>
            <span>文章标题</span>
            <el-button class="button" type="text">查看详细</el-button>
          </template>
          <el-row :gutter="250">

            <el-col :span="5">
              <img src="../../assets/tu1.png" style="width: 230px; height: 140px" fit="cover">
            </el-col>

            <el-col :span="17">
              <el-row>
                <el-col>
                  {{ Posts.neirong }}
                </el-col>
                <el-col>
                  <el-divider content-position="left">
                    {{ '作者:' + Posts.zuozhe }}
                    点赞 收藏 留言:94984 浏览:979898987
                  </el-divider>
                </el-col>
              </el-row>
            </el-col>

          </el-row>
        </el-card>
      </ul>

      <el-pagination
          id="yema" background layout="prev, pager, next"
          :total="total"
          v-model:current-page="CurrentPage"
          :pager-count="PagerCount"
          :page-size="PageSize"/>
      当前处于第{{ CurrentPage }}页,共有{{ total }}条数据。

    </el-main>

    <el-aside style="width: 350px;">

    </el-aside>

  </el-container>

</template>

<script>
import axios from "axios";

export default {
  name: "HomePage",
  data() {
    return {
      //数据总条数
      total: 2000,
      //当前页数
      CurrentPage: 1,
      //页码数量
      PagerCount: 13,
      //每页显示数据条数
      PageSize: 10,

      activeIndex: '1',
      activeIndex2: '1',

      wenben: [
        {
          neirong: "春，送别了冷冷的冬寒，飘过季节轮回的光阴古道。用一身明媚的阳光，温润着大地的胸怀。将山川冰封着的心复苏，把小草从冬眠的梦中唤醒，让飘飞的柳絮化作了点点岁月的流光，更在清风舞柳的暖阳中寻找着时光的明媚。",
          zuozhe: "wenhao", riqi: new Date()
        },
        {
          neirong: "春，送别了冷冷的冬寒，飘过季节轮回的光阴古道。用一身明媚的阳光，温润着大地的胸怀。将山川冰封着的心复苏，把小草从冬眠的梦中唤醒，让飘飞的柳絮化作了点点岁月的流光，更在清风舞柳的暖阳中寻找着时光的明媚。",
          zuozhe: "wenhao", riqi: new Date()
        },
        {
          neirong: "春，送别了冷冷的冬寒，飘过季节轮回的光阴古道。用一身明媚的阳光，温润着大地的胸怀。将山川冰封着的心复苏，把小草从冬眠的梦中唤醒，让飘飞的柳絮化作了点点岁月的流光，更在清风舞柳的暖阳中寻找着时光的明媚。",
          zuozhe: "wenhao", riqi: new Date()
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

    huoqu: function () {
      alert("获取数据");
      axios.post("/user/he").then(res => {
        console.log(res);
        //将数据赋值到vue实例中的数据属性users；
        //不能使用this，在axios回调函数中表示窗口，不是vue实例
        alert(res.data);
        // app.lists = res.data;
      }).catch(err => alert(err));
    }

  },
  created() {
    //this.setsize(2000);
  },
  //监听器
  watch: {
    CurrentPage() {
      // 当CurrentPage数据发生变化以后执行方法
      alert("请求第"+this.CurrentPage+"页的数据");
    }
  }
}
</script>

<style scoped>

</style>