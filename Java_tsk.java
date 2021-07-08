package com.company;
/*
Создать класс "Матрица". Класс должен иметь следующие поля:
1) двумерный массив вещественных чисел;
2) количество строк и столбцов в матрице.

Класс должен иметь следующие методы:
1) сложение с другой матрицей;
2) умножение на число;
3) вывод на печать;
4) умножение матриц - по желанию.
 */
public class Main {
    public static void main(String[] args) {
        double[][] first_matrix = new double[2][2];
        matrix first = new matrix(2,2,first_matrix);
        double[][] second_matrix = new double[2][2];
        matrix second = new matrix(2,2,second_matrix);
        first.fill_random();
        second.fill_random();
        System.out.println("First matrix:");
        first.print_matrix_1();
        System.out.println("Second matrix");
        second.print_matrix_1();
        System.out.println("Sum result:");
        matrix new_m = matrix.sum(first,second);
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                System.out.print(new_m.double_matrix[i][j] + "  ");
            }
            System.out.println("\n");
        }
        System.out.println("");
        System.out.println("Mult 1 res:");
        (matrix.multiplication_by_number(3,first)).print_matrix_1();
        (matrix.multiplication(first,second)).print_matrix_1();
    }
}

class matrix{
    public double[][] double_matrix;
    private final int raws,columns;
    public matrix(int raws,int columns,double[][] double_matrix){
        this.double_matrix = new double[raws][columns];
        this.raws = raws;
        this.columns = columns;
        this.double_matrix = double_matrix;
    }
    public void fill_random(){
        for(int i = 0;i < raws;i++){
            for(int j = 0;j < columns;j++){
                double_matrix[i][j] = (int)(Math.random()*10);
            }
        }
    }
    public static matrix sum(matrix first_matrix,matrix second_matrix){
        if(first_matrix.columns != second_matrix.columns || first_matrix.raws != second_matrix.raws){
            System.out.println("Cannot do the operation");
            return null;
        }
        double[][] new_matrix = new double[first_matrix.raws][first_matrix.columns];
        for(int i = 0;i < first_matrix.raws;i++){
            for(int j = 0;j < first_matrix.columns;j++){
                new_matrix[i][j] = first_matrix.double_matrix[i][j] + second_matrix.double_matrix[i][j];
            }
        }

        return new matrix(first_matrix.raws, first_matrix.columns, new_matrix);
    }
    public static matrix multiplication_by_number(int number,matrix matrix_object){
        double[][] new_double_matrix = new double[matrix_object.raws][matrix_object.columns];
        for(int i = 0;i < matrix_object.raws;i++){
            for(int j = 0;j < matrix_object.columns;j++){
                new_double_matrix[i][j] = number*matrix_object.double_matrix[i][j];
            }
        }
        return new matrix(matrix_object.raws, matrix_object.columns, new_double_matrix);
    }
    public static matrix multiplication(matrix first_matrix,matrix second_matrix){
        double[][] result_matrix = new double[first_matrix.raws][second_matrix.columns];
        if(first_matrix.columns == second_matrix.raws){
            for (int i = 0;i < first_matrix.raws;i++){
                for(int j= 0;j < second_matrix.columns;j++){
                    double result = 0;
                    for(int z = 0;z < second_matrix.raws;z++){
                        result += first_matrix.double_matrix[i][z]*second_matrix.double_matrix[z][j];
                    }
                    result_matrix[i][j] = result;
                }
            }
        }
        return new matrix(first_matrix.raws,second_matrix.columns,result_matrix);
    }
    public void print_matrix_1(){
        for(int i = 0;i < this.raws;i++){
            for(int j = 0;j < this.columns;j++){
                System.out.print(this.double_matrix[i][j] + "  ");
            }
            System.out.println("\n");
        }
        System.out.println("");
    }
}
