<template>
  <div class="common-layout">
    <el-container style="width: 1500px;">

      <el-aside style="width: 70px">

      </el-aside>

      <el-main style="width: 780px;">
        <el-tabs type="border-card" class="demo-tabs">
          <el-row class="box-card" shadow="hover" style="text-align:left;">

            <el-col>
              <font size="5">{{ this.dataBody.title }}</font>
              <!--              当前文章id:{{ ArticleId }}-->
            </el-col>

            <el-col>
              <img src="../../assets/tu2.png" style="width: 100%" fit="cover">
              <el-link style="color:blue;">作者</el-link>
              :{{ this.dataBody.username }}&nbsp;&nbsp;
              {{ '时间:' + this.dataBody.issuingTime }}&nbsp;&nbsp;
              <el-divider></el-divider>
            </el-col>

            <el-col>
              <el-main>
                <div v-html="this.dataBody.body"/>
              </el-main>
              
            </el-col>

          </el-row>
        </el-tabs>

      </el-main>

      <el-aside style="width: 550px;">
        <el-affix :offset="10">固定</el-affix>
        <el-tabs type="border-card" class="demo-tabs">
          <el-tab-pane>
            <template #label>
        <span class="custom-tabs-label">
          <el-icon><calendar/></el-icon>
          <span>简介</span>
        </span>
            </template>
            <el-row style="margin-top: 10px">
              简介:{{ dataBody.synopsis }}
            </el-row>
            <el-row content-position="left" style="margin-top: 10px">
              <el-col :span="4" style="margin-left: 8px">
                <el-link type="warning" v-on:click="goToLikeArticle">点赞</el-link>
                :{{ dataBody.likeNumber }}
              </el-col>
              <el-col :span="4" style="margin-left: 8px">
                <el-link type="warning" v-on:click="Collection">收藏</el-link>
                :{{ dataBody.favoritesNumber }}
              </el-col>
            </el-row>
            <el-row style="float: left;margin-top: 10px">
              <el-check-tag checked style="margin-right: 8px;margin-top: 5px">学习分享</el-check-tag>
              <el-check-tag checked style="margin-right: 8px;margin-top: 5px">散文</el-check-tag>
              <el-check-tag checked style="margin-right: 8px;margin-top: 5px">文字</el-check-tag>
            </el-row>
          </el-tab-pane>

          <el-tab-pane label="热门评论">
            <div v-if="CommentList[0].Id!=null">
              <el-row v-for="(item,key) in CommentList" :key="key" style="margin-top: 20px">
                <el-col>
                  <el-popover
                      :width="300"
                      popper-style="box-shadow: rgb(14 18 22 / 35%) 0px 10px 38px -10px, rgb(14 18 22 / 20%) 0px 10px 20px -15px; padding: 20px;"
                      trigger="click"
                      :content="{item,key}"
                  >
                    <template #reference>

                      <el-row :gutter="2">
                        <el-col :span="2">
                          <el-avatar :size="40" src="{{item.CommentBy.imgUrl}}"/>
                        </el-col>
                        <el-col :span="5">
                          <el-link type="danger" style="margin-top: 10%">{{ item.CommentBy.name }}</el-link>
                        </el-col>
                      </el-row>

                    </template>

                    <template #default>
                      <div class="demo-rich-conent" style="display: flex; gap: 16px; flex-direction: column">

                        <el-avatar :size="60" src="{{item.CommentBy.imgUrl}}"
                                   style="margin-bottom: 8px"/>

                        <div>
                          <p class="demo-rich-content__name" style="margin: 0; font-weight: 500">
                            {{ item.CommentBy.name }}:
                            <el-link style="margin-left: 8px">{{ item.CommentBy.email }}</el-link>
                          </p>
                          <p class="demo-rich-content__mention"
                             style="margin: 0; font-size: 14px; color: var(--el-color-info)">
                            <el-link style="margin-right: 8px">私信TA</el-link>
                            <el-link style="margin-right: 8px">关注TA</el-link>
                          </p>
                        </div>

                        <p class="demo-rich-content__desc" style="margin: 0">
                          个人简介{{ item }}
                        </p>
                      </div>
                    </template>
                  </el-popover>
                </el-col>

                <el-col>
                  <el-popover
                      :width="300"
                      trigger="click"
                      :content="{item}"
                  >
                    <template #reference>
                      <el-link type="warning">{{ item.Reviewed.name }}</el-link>
                    </template>
                    <template #default>
                      <div class="demo-rich-conent" style="display: flex; gap: 16px; flex-direction: column">

                        <el-avatar :size="60" src="{{item.Reviewed.imgUrl}}"
                                   style="margin-bottom: 8px"/>

                        <div>
                          <p class="demo-rich-content__name" style="margin: 0; font-weight: 500">
                            {{ item.Reviewed.name }}:
                            <el-link style="margin-left: 8px">{{ item.Reviewed.email }}</el-link>
                          </p>
                          <p class="demo-rich-content__mention"
                             style="margin: 0; font-size: 14px; color: var(--el-color-info)">
                            <el-link style="margin-right: 8px">私信TA</el-link>
                            <el-link style="margin-right: 8px">关注TA</el-link>
                          </p>
                        </div>

                        <p class="demo-rich-content__desc" style="margin: 0">
                          个人简介{{ item }}
                        </p>
                      </div>
                    </template>
                  </el-popover>
                  {{ item.Comments }}
                </el-col>

                <el-col>
                  <el-link type="primary" style="margin-right: 5px;float: right">点赞</el-link>
                  <el-popover
                      placement="bottom"
                      title="回复TA"
                      :width="400"
                      trigger="click"
                      :content="item"
                  >
                    <template #reference>
                      <el-link type="primary" style="margin-right: 5px;float: right">回复TA</el-link>
                    </template>

                    <el-col content-position="left">
                      <el-input
                          style="width: 400px;"
                          v-model="ReplyToComments"
                          :autosize="{ minRows: 5, maxRows: 20 }"
                          type="textarea"
                      />
                    </el-col>
                    <el-col style="margin-top: 10px">
                      <el-button v-on:click="SubmitReplyToComment(item.Id,ReplyToComments)">提交评论</el-button>
                      <el-button>添加表情</el-button>
                      <el-button>添加图片</el-button>
                    </el-col>

                  </el-popover>
                </el-col>
                <el-col>
                  <el-link type="info" style="float: right">点赞数:{{ item.likeNumber }}</el-link>
                </el-col>
                <el-divider content-position="left"></el-divider>
              </el-row>
              <el-row>
                <el-pagination
                    id="yema" background layout="prev, pager, next"
                    :total="dataBody.commentsNumber"
                    v-model:current-page="CurrentPage"
                    :pager-count="PagerCount"
                    :page-size="PageSize"/>
                当前处于第{{ CurrentPage }}页,共有{{ dataBody.commentsNumber }}条数据。
              </el-row>
            </div>
            <div v-if="CommentList[0].Id==null">
              <el-link v-on:click="getReviews">获取所有评论</el-link>
              {{ dataBody.commentsNumber }}
              <el-alert title="还没有任何评论" type="info" :closable="false"/>
            </div>
          </el-tab-pane>
          <el-tab-pane label="评论">
            <el-col content-position="left">
              <el-input
                  style="width: 500px;"
                  v-model="CommentBox.body"
                  :autosize="{ minRows: 5, maxRows: 20 }"
                  :clearable="{ArticleId,CommentBox}"

                  type="textarea"
                  placeholder="满朝文武,为何支支吾吾?"
              />
            </el-col>
            <el-col style="margin-top: 10px">
              <el-button v-on:click="SubmitArticleComments(ArticleId,CommentBox.body)">提交评论</el-button>
              <el-button>添加表情</el-button>
              <el-button>添加图片</el-button>
            </el-col>
          </el-tab-pane>
          <el-tab-pane label="最新评论">最新评论</el-tab-pane>
        </el-tabs>
      </el-aside>

    </el-container>

  </div>
</template>


<script>
import {getReviews, huoqu, SubmitArticleComments} from "@/api";

export default {
  name: "WenZhan",
  data() {
    return {
      //评论数据总条数
      //total: 200, = dataBody.commentsNumber
      //当前评论页
      CurrentPage: 1,
      //页码数量
      PagerCount: 8,
      //每页显示评论数据条数
      PageSize: 10,

      //评论集合
      CommentList: [{
        Id: null,//评论id
        CommentBy: {//发评论者信息(昵称、账号、头像路径) id
          name: null, email: null, imgUrl: null,
        },
        Reviewed: {// 被@者信息(昵称、账号、头像路径) id
          name: null, email: null, imgUrl: null,
        },
        ArticleId: null, // 文章id(前端不需要展示)
        CommentId: null,// 回复的评论id(前端不需要展示)
        Comments: null, // 评论内容
        likeNumber: null,
        CommentTime: null, // 评论时间(需要排序)
      }],

      CommentBox: {
        id: '',//回复的文章id
        body: '',//输入的评论内容
      },

      ReplyToComments: '',//输入的回复评论内容
      NumberofLikes: 0,//文章点赞数
      NumberOfCollections: 0,//文章收藏数

      ArticleId: '',//当前文章id
      dataBody: {
        id: '',
        title: '',
        body: '',
        username: '',
        issuingTime: '',
        likeNumber: '',
        favoritesNumber: '',
        commentsNumber: '',
      }
    }
  },
  methods: {
    //点赞文章
    goToLikeArticle() {
      this.NumberofLikes += 1;
    },
    //收藏文章
    Collection() {
      this.NumberOfCollections += 1;
    },
    //点赞评论
    goToLikeComment() {

    },
    //提交评论(给文章留下评论)
    SubmitArticleComments(key, CommentBox) {
      this.CommentBox.id = key;
      alert("此操作将回复id为:" + key + "的文章,回复内容为:" + CommentBox);
      SubmitArticleComments(this.CommentBox).then(res => {
        alert(res.data);
      }).catch(err => console.log(err))
      this.ReplyToComments = '';
    },
    //提交回复评论(给评论留下评论)
    SubmitReplyToComment(key, ReplyToComments) {
      alert("此操作将回复id为:" + key + "的评论,回复内容为:" + ReplyToComments);
      this.ReplyToComments = '';
    },
    //获取评论
    getReviews() {
      getReviews(this.ArticleId, this.CurrentPage).then(res => {
        //将JSON字符串转为JSON对象
        console.log(res.data);
        if(true===JSON.parse(res.data).code){
          this.CommentList = JSON.parse(res.data).datas
        }else {
          alert("没有更多数据了")
        }

        // if (true===res.data.news){
        //   this.CommentList = JSON.parse(res.data.data);
        // }else {
        //   alert("没有数据了")
        // }


        //
      }).catch(err => alert(err))
    },

  },
  watch: {
    CurrentPage (newName, oldName) {
      this.getReviews();
      console.log(newName+oldName)
    }
  },


  created() {
    this.ArticleId = this.$route.query.value;

    huoqu({ArticleId: this.ArticleId}).then(res => {
      console.log(res);
      this.dataBody = JSON.parse(res.data);
    }).catch(err => alert(err));


  }
}
</script>

<style>
ql-video {
  width: 100%;
  height: 500px;
}
</style>