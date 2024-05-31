package initial;

import java.io.*;
//파일 처리용 메서드들을 포함하는 패키지

public class FileReading {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File textFile = new File ("my_textfile.txt"); //새 text file 생성 
		try {
			boolean fileCreated = textFile.createNewFile(); 
			//생성이 정상적으로 완료되었으면 true 를, 아니면 false 를 저장 
			if (fileCreated) { //파일이 제대로 생성되었는지 확인 
				System.out.println("Creation Successed!\n");
			}
			else {
				System.out.println("Creation Failed!\n");
			}
		}catch(IOException e) { //생성 오류 발생시 오류메시지 출력 
			System.out.println("file creation failed: "+e.getMessage());
		}
		
		String str = "Object-Oriented Programming, 2024 Spring!"; //파일에 넣을 문자열 
		try {
			FileOutputStream fos = new FileOutputStream(textFile); //바이트 출력 스트림 유형 
			//출력을 하는 추상클래스, 바이트 출력 스트림을 나타내는 모든 클래스의 슈퍼클래스 
			byte[] bytes = str.getBytes(); 
			fos.write(bytes); //파일에 str을 적음 
			fos.close();
			System.out.println("Writing Succeeded!\n");
			
		}catch(Exception e) { //쓰기 오류 발생시 오류메시지 출력 
			System.out.println("file writing failed: " + e.getMessage());
		}
		
		try {
			FileInputStream fis = new FileInputStream(textFile); //바이트 출력 스트림 유형 
			//출력을 하는 추상클래스, 바이트 출력 스트림을 나타내는 모든 클래스의 슈퍼클래스 
			int i=0;
			while ((i=fis.read())!=-1) {
				System.out.print((char)i);
			}
			fis.close();
			System.out.println("\nReading Succeeded!\n");
			
		}catch(Exception e) { //쓰기 오류 발생시 오류메시지 출력 
			System.out.println("file reading failed: " + e.getMessage());
		}
		
		
		//추가로 한번 실행해본 부분 
		if (textFile.exists()) {
			System.out.println("File name: "+textFile.getName()); //파일의 이름 
			System.out.println("File path: "+textFile.getAbsolutePath()); //파일의 경로
			System.out.println("File can write: "+textFile.canWrite()); //파일 쓰기가 가능한지
			System.out.println("File can read: "+textFile.canRead()); //파일 읽기가 가능한지
			System.out.println("File length: "+textFile.length()); // 파일의 크기 
		}
		else {
			System.out.println("No file here");
		}
	}

}
