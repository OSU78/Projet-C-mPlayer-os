-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3308
-- Generation Time: Jan 05, 2020 at 11:50 AM
-- Server version: 5.7.24
-- PHP Version: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `c_project`
--

-- --------------------------------------------------------

--
-- Table structure for table `collection`
--

CREATE TABLE `collection` (
  `id_song` int(11) NOT NULL,
  `id_username` varchar(30) NOT NULL,
  `title` varchar(45) NOT NULL,
  `singer` varchar(45) NOT NULL,
  `band` varchar(45) NOT NULL,
  `genre` varchar(45) NOT NULL,
  `duration` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `collection`
--

INSERT INTO `collection` (`id_song`, `id_username`, `title`, `singer`, `band`, `genre`, `duration`) VALUES
(1, 'Trofa', 'nice', 'value-4', 'value-5', 'value-6', 'value-7'),
(2, 'Trofa', '', '', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `games`
--

CREATE TABLE `games` (
  `id_game` int(11) NOT NULL,
  `game` int(11) NOT NULL,
  `uscore` int(11) NOT NULL,
  `leaderboards` int(11) NOT NULL,
  `id_username` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `games`
--

INSERT INTO `games` (`id_game`, `game`, `uscore`, `leaderboards`, `id_username`) VALUES
(4, 2, 10, 10, 'LMAO'),
(5, 2, 20, 20, 'LMAO'),
(6, 2, 0, 0, 'trofa'),
(7, 2, 50, 50, 'trofa'),
(9, 2, 30, 30, 'LMAO'),
(10, 2, 40, 40, 'LMAO'),
(12, 2, 0, 0, ''),
(13, 1, 50, 50, 'LMAO'),
(14, 1, 20, 20, 'trofafr'),
(15, 1, 70, 70, 'trofafr'),
(16, 1, 110, 110, 'trofafr'),
(17, 2, 20, 20, ''),
(18, 2, 30, 30, ''),
(19, 2, 40, 40, ''),
(20, 2, 50, 50, ''),
(21, 3, 90, 90, '');

-- --------------------------------------------------------

--
-- Table structure for table `playlist`
--

CREATE TABLE `playlist` (
  `id_playlist` int(11) NOT NULL,
  `id_song` int(11) NOT NULL,
  `id_username` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `username` varchar(40) NOT NULL,
  `password` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`username`, `password`) VALUES
('', ''),
('azdaz', 'azdza'),
('azeazeazeaze', 'azeazezae'),
('azerty', 'azerty'),
('azezaazazfaz', ''),
('cx', 'cq'),
('effzefzafa', 'zadazdazd'),
('LMAO', 'AZ'),
('New', 'azazzz'),
('patarata', '0000xpto'),
('test', 'test1'),
('test123', 'test223'),
('testetet', 'tetete'),
('Trofa', 'ushallnotknowmypassword'),
('trofafr', '&&&&'),
('victan', 'hellovictan'),
('zaza', 'azaz');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `collection`
--
ALTER TABLE `collection`
  ADD PRIMARY KEY (`id_song`),
  ADD KEY `id_username` (`id_username`);

--
-- Indexes for table `games`
--
ALTER TABLE `games`
  ADD PRIMARY KEY (`id_game`) USING BTREE;

--
-- Indexes for table `playlist`
--
ALTER TABLE `playlist`
  ADD PRIMARY KEY (`id_playlist`),
  ADD KEY `id_song` (`id_song`),
  ADD KEY `id_username` (`id_username`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`username`) USING BTREE;

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `collection`
--
ALTER TABLE `collection`
  MODIFY `id_song` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `games`
--
ALTER TABLE `games`
  MODIFY `id_game` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT for table `playlist`
--
ALTER TABLE `playlist`
  MODIFY `id_playlist` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `collection`
--
ALTER TABLE `collection`
  ADD CONSTRAINT `collection_ibfk_1` FOREIGN KEY (`id_username`) REFERENCES `user` (`username`),
  ADD CONSTRAINT `collection_ibfk_2` FOREIGN KEY (`id_username`) REFERENCES `user` (`username`);

--
-- Constraints for table `playlist`
--
ALTER TABLE `playlist`
  ADD CONSTRAINT `playlist_ibfk_1` FOREIGN KEY (`id_song`) REFERENCES `collection` (`id_song`),
  ADD CONSTRAINT `playlist_ibfk_2` FOREIGN KEY (`id_username`) REFERENCES `user` (`username`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
