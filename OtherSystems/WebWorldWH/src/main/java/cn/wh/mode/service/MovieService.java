package cn.wh.mode.service;

import cn.wh.mode.pojo.Movie;
import com.baomidou.mybatisplus.extension.service.IService;

import java.io.File;
import java.util.List;

/**
* @author XMZR
* @description 针对表【movie】的数据库操作Service
* @createDate 2022-05-06 09:41:21
*/
public interface MovieService extends IService<Movie> {
    //添加一个movie
    boolean addMovie(File movieFile);

    //删除指定id movie
    boolean deleteMovie(Integer movieId);

    //更新一个movie的信息
    boolean updateMovie(Movie movie);

    //查询所有movie信息
    List<Movie> queryMovieList();

    //查询指定id movie信息
    Movie queryMovieOne(Integer movieId);

    boolean setMovieFileOfData(File file);

}
