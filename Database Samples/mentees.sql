-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 13, 2021 at 11:31 PM
-- Server version: 10.4.18-MariaDB
-- PHP Version: 8.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `honors_app`
--

-- --------------------------------------------------------

--
-- Table structure for table `mentees`
--

CREATE TABLE `mentees` (
  `id` int(20) NOT NULL,
  `firstName` varchar(255) NOT NULL,
  `lastName` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `major` varchar(255) NOT NULL,
  `topic` varchar(11) NOT NULL,
  `group_id` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `mentees`
--

INSERT INTO `mentees` (`id`, `firstName`, `lastName`, `email`, `major`, `topic`, `group_id`) VALUES
(19, 'Coleen', 'Bindin', 'cbindin0@issuu.com', 'Computer Science', 'Zero Hunger', 1),
(25, 'Hammad', 'Panswick', 'hpanswick8@furl.net', 'Engineering Science', 'Clean Water', 4),
(29, 'Jason', 'Bones', 'jason@gmail.com', 'Computer Information Systems', 'Green Consu', NULL),
(30, 'Mir', 'Humaira', 'mir@gmail.com', 'Computer Science', 'Zero Hunger', 1),
(31, 'Anna', 'Smith', 'annasm@gmail.com', 'Computer Science', 'Quality Edu', 3),
(33, 'James', 'Hook', 'jay@gmail.com', 'Computer Information Systems', 'Quality Edu', 3),
(35, 'Harry', 'Hook', 'harryh@gmail.com', 'Computer Science', 'Quality Edu', 3),
(36, 'Valeria', 'Puente', 'val@gmail.com', 'Computer Information Systems', 'Clean Water', 4),
(37, 'José', 'Nunes', 'jose@gmail.com', 'Computer Information Systems', 'Clean Water', 4);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `mentees`
--
ALTER TABLE `mentees`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `mentees`
--
ALTER TABLE `mentees`
  MODIFY `id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
