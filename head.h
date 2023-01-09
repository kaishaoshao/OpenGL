#pragma once
//GLAD文件需要放在GLFW文件上面
//原因是GLAD的include文件包含OpenGL的头文件
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/**********状态机 - 上下文 - 对象*************/
//状态机：OpenGL自身是一个巨大的状态机(State Machine)
//上下文：OpenGL的状态通常被称为OpenGL上下文(Context)
//改变状态：设置选项，操作缓冲。最后，我们使用当前OpenGL上下文来渲染。
//对象：是指一些选项的集合，它代表OpenGL状态的一个子集

//使用对象的工作流
void Use_object();

/********************GLFW-GLAD****************/
//GLFW  解决操作系统不同 提供窗口 定义上下文 处理用户输入
//GLAD  解决不同的OpenGL驱动 本地指针到代码映射
//创建一个OpenGL窗口
int Create_firstWindows();




