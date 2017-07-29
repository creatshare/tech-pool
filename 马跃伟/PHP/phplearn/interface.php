<?php
/**
 * Created by PhpStorm.
 * User: DELL-XPS
 * Date: 2017/7/20
 * Time: 16:20
 */
interface IPillage{
    function emptyBlankAccount();
    function burnDocuments();
}
interface IEmployee{
    function assistant();
}
interface IDevelopment{
    function Tortch();
}
class Employeee implements IPillage,IEmployee,IDevelopment{
    //具体实现三个接口中的方法
}
class Contractor implements IPillage,IDevelopment{
    //这个就只实现两个接口
}

