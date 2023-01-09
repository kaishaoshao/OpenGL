#include"head.h"
using namespace std;

void Use_object()
{
	/*
		// ��������
		unsigned int objectId = 0;
		// ��һ��id������������
		glGenObject(1, &objectId); //����һ������  objectId �����������
		// �󶨶�����������
		glBindObject(GL_WINDOW_TARGET, objectId);
		// ���õ�ǰ�󶨵� GL_WINDOW_TARGET �Ķ����һЩѡ��
		glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH, 800);
		glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
		// �������Ķ������Ĭ��
		glBindObject(GL_WINDOW_TARGET, 0);
		*/
	return ;
}

int Create_firstWindows()
{  
	/*�������ڵĲ���
	   1-��ʼGLFW
	      (1)....��ʼ��GLFW
		  (2)....���ô��ڰ汾�š�����ģʽ
		  (3)....����GLFW���� ���оͻ���
		  (4)....����GLFW����������

	   2-��ʼGLAD
	   (1)....����ϵͳOpenGLָ��
	   (2)....��Ⱦѭ��(Render Loop) 
	       1)....״̬����
		   2)....״̬ʹ��
		   3)....ǰ������
		   4)....�󻺳���

	   3-����GLFW
	*/

	/****************GLFW*****************/
	//��ʼ��GLFW
	glfwInit();
	//���ð汾���ǽ����汾��(Major)�ʹΰ汾��(Minor)����Ϊ3��Ҳ����openGL3.3 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//����ͬ����ȷ����GLFW����ʹ�õ��Ǻ���ģʽ(Core-profile)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//��������
	GLFWwindow* window = glfwCreateWindow(400, 300, "FirstOpenGLWindow", NULL, NULL);
	if (window == nullptr)
	{
		cout << "Failed to Create GLFW window" << endl;
		//����GLFW
		glfwTerminate();
		return -1;
	}

	//GLFW�����ڵ�����������Ϊ��ǰ�̵߳�������
	glfwMakeContextCurrent(window);


	/****************GLAD*****************/
	//glad:����ϵͳ��ص�OpenGL����ָ���ַ
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	//��Ⱦѭ��(Render Loop)
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //״̬����
		glClear(GL_COLOR_BUFFER_BIT);         //״̬ʹ��
		//glfw����������������ѯIO�¼����������¡�����ͷŵȣ����´���״̬�������ö�Ӧ�Ļص�����
		//˫����(Double Buffer)
		glfwSwapBuffers(window); //ǰ����������Ļ����ʾ��ͼ�� ������ɫ����
		glfwPollEvents();        //�󻺳�����������Ⱦ��ͼ��
	}
	//glfw:����ǰ������GLFW�����Դ
	glfwTerminate();
	return 0;
}
