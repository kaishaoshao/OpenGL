#pragma once
//GLAD�ļ���Ҫ����GLFW�ļ�����
//ԭ����GLAD��include�ļ�����OpenGL��ͷ�ļ�
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/**********״̬�� - ������ - ����*************/
//״̬����OpenGL������һ���޴��״̬��(State Machine)
//�����ģ�OpenGL��״̬ͨ������ΪOpenGL������(Context)
//�ı�״̬������ѡ��������塣�������ʹ�õ�ǰOpenGL����������Ⱦ��
//������ָһЩѡ��ļ��ϣ�������OpenGL״̬��һ���Ӽ�

//ʹ�ö���Ĺ�����
void Use_object();

/********************GLFW-GLAD****************/
//GLFW  �������ϵͳ��ͬ �ṩ���� ���������� �����û�����
//GLAD  �����ͬ��OpenGL���� ����ָ�뵽����ӳ��
//����һ��OpenGL����
int Create_firstWindows();




